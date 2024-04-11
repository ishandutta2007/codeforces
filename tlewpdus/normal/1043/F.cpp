#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const int SQ = 550;
const int MAX = 300010;

int n;
int arr[300100];
int chk[300100];
int moe[300100];
int shk[300100];
int dp[300100];

int gcd(int a, int b){
    return a?gcd(b%a,a):b;
}

ll po(ll a, ll n, ll m) {
    if (!n) return 1;
    ll t = po(a,n/2,m);
    return t*t%m*(n%2?a:1)%m;
}

ll mod[3] = {1000000007,1000000009,1000000021};
ll fac[3][300100];
ll fnv[3][300100];
ll comb(ll n, ll r, ll moi){
    if (r<0||n<r) return 0;
    return fac[moi][n]*fnv[moi][r]%mod[moi]*fnv[moi][n-r]%mod[moi];
}

int main() {
    int i, j;

    scanf("%d",&n);
    vector<int> vec;
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int g = 0;
    for (int &v : vec) g = gcd(g,v);
    if (g>1) {
        printf("-1\n");
        return 0;
    }
    int f = 0;
    for (int &v : vec) if (v==1) f = 1;
    if (f) {
        printf("1\n");
        return 0;
    }
    memset(chk,0,sizeof(chk));
    for (int &v : vec) chk[v] = 1;
    for (i=1;i<=MAX;i++) {
        shk[i] = 0;
        for (j=i;j<=MAX;j+=i) if (chk[j]) shk[i]++;
    }
    moe[1] = 1;
    for (i=1;i<=MAX;i++){
        for (j=2*i;j<=MAX;j+=i) moe[j] -= moe[i];
    }
    int t;
    for (int s=0;s<3;s++) {
        fac[s][0] = 1;
        for (i=1;i<=MAX;i++) fac[s][i]=fac[s][i-1]*i%mod[s];
        for (i=0;i<=MAX;i++) fnv[s][i]=po(fac[s][i],mod[s]-2,mod[s]);
    }
    for (t = 2;t<10;t++) {
        int fl = 0;
        for (int s = 0;s<3;s++){
            ll sum = 0;
            for (i=1;i<=MAX;i++) sum += moe[i]*comb(shk[i],t,s);
            sum = sum%mod[s];
            if (sum) {fl = 1; break;}
        }
        if (fl) break;
    }
    printf("%d\n",t);

    return 0;
}