#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
ll mod=1000000007;

pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
int modInverse(ll a, ll m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

//int ans=0;
vi inv(100001);
for(int i=1; i<100001; i++) inv[i]=modInverse(i, mod);
int n,k;
cin>>n>>k;

char c;
vll a;
for(int i=0; i<n; i++) {
    cin>>c;  
    a.pb(c-'0');
}
ll p10=1;
if(n==1){
    cout<<a[0];
    return 0;
}

ll sum = 0;
ll ans = 0;
ll cn1k=1;
if(k==0) {
    for(int j=n-1; j>=0; j--) {
        ans=(ans+a[j]*p10) % mod;
        p10*=10;
    }
    cout<<ans;
    return 0;
}
for(int j=1; j<=k; j++) {
    cn1k = (cn1k * (n-j)) % mod;
    cn1k = (cn1k * inv[j]) % mod;
}
vll cxk(n);
vll cxk1(n);
cxk[n-1] = cn1k;
for(int j= n-2; j>=k; j--) {
    ll newc = cxk[j+1];
    newc = (newc * (j + 1 - k)) % mod;
    newc = (newc * inv[j+1]) % mod;
    cxk[j]=newc;
}
for(int j=n-2; j>=k-1; j--) {
    ll newc=cxk[j+1];
    newc = (newc * k) % mod;
    newc = (newc * inv[j+1]) % mod;
    cxk1[j]=newc;
}
for(int i=0; i<n; i++) {
    sum+=a[i];

}

for(int j=0; j<=n-1-k; j++) {
    sum-=a[n-1-j];
    ans+=(((sum*p10) % mod) * cxk1[n-2-j]) % mod;
    
    ans+= (((p10*a[n-1-j]) % mod) * cxk[n-1-j])% mod;
    ans= ans%mod;
    p10*=10;
    p10 = p10%mod;
}
cout<<ans;

return 0;


}