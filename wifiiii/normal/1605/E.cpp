#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int prime[maxn],np[maxn],mu[maxn],phi[maxn],tot=0;
void init(int n) {
   np[1]=mu[1]=phi[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot]=i,mu[i]=-1,phi[i]=i-1;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           if(i%prime[j]==0) {
               np[i*prime[j]]=1;
               mu[i*prime[j]]=0;
               phi[i*prime[j]]=phi[i]*prime[j];
               break;
           }
           np[i*prime[j]]=1;
           mu[i*prime[j]]=-mu[i];
           phi[i*prime[j]]=phi[i]*(prime[j]-1);
       }
   }
}

vector<int> fac[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < maxn; ++i) {
        for(int j = i + i; j < maxn; j += i) {
            fac[j].push_back(i);
        }
    }
    init(maxn - 1);
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<ll> s(n + 1);
    vector<ll> inc, dec;
    ll sum = 0;
    for(int i = 2; i <= n; ++i) {
        ll tmp = 0;
        for(int d : fac[i]) {
            tmp += mu[d] * (b[i / d] - a[i / d]);
        }
        s[i] = tmp;
        if(mu[i] == 1) inc.push_back(tmp);
        else if(mu[i] == -1) dec.push_back(tmp);
        else sum += abs(tmp);
    }
    sort(inc.begin(), inc.end());
    sort(dec.begin(), dec.end());
    vector<ll> sinc(inc.size() + 1), sdec(dec.size() + 1);
    for(int i = 0; i < inc.size(); ++i) sinc[i + 1] = sinc[i] + inc[i];
    for(int i = 0; i < dec.size(); ++i) sdec[i + 1] = sdec[i] + dec[i];
    auto calc = [&](const vector<ll> &a, const vector<ll> &s, int k) -> ll {
        int n = a.size();
        if(k >= 0) {
            int l = lower_bound(a.begin(), a.end(), -k) - a.begin();
            int r = lower_bound(a.begin(), a.end(), 0) - a.begin();
            // [0, l) , [l, r) , [r, n)
            ll left = abs(s[l]) - 1ll * l * k;
            ll mid = 1ll * (r - l) * k - abs(s[r] - s[l]);
            ll right = abs(s[n] - s[r]) + 1ll * (n - r) * k;
            return left + mid + right;
        } else {
            int l = lower_bound(a.begin(), a.end(), 0) - a.begin();
            int r = lower_bound(a.begin(), a.end(), -k) - a.begin();
            // [0, l), [l, r), [r, n)
            ll left = abs(s[l]) + 1ll * l * (-k);
            ll mid = 1ll * (r - l) * (-k) - abs(s[r] - s[l]);
            ll right = abs(s[n] - s[r]) - 1ll * (n - r) * (-k);
            return left + mid + right;
        }
        return 0;
    };
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        k -= a[1];
        ll ans = abs(k) + sum + calc(inc, sinc, k) + calc(dec, sdec, -k);
        cout << ans << '\n';
    }
}