#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100005;
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

const int mod = 1e9 + 7;
int cnt[100005];
int main() {
    init(maxn - 1);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> aa(a.begin()+1,a.end());
    auto solve = [&](vector<int> a) -> ll {
        int n = a.size();
        if(a.size() <= 200) {
            ll ret = 0;
            for(int i = 0; i < n; ++i) {
                ret += a[i];
                for(int j = i + 1; j < n; ++j) {
                    ret += gcd(a[i], a[j]) * 2;
                }
            }
            ret %= mod;
            return ret;
        }
        for(int i : a) cnt[i]++;
        int mx = *max_element(a.begin(), a.end());
        ll ret = 0;
        for(int i = 1; i <= mx; ++i) {
            ll tmp = 0;
            for(int j = i; j <= mx; j += i) {
                tmp += cnt[j];
            }
            tmp %= mod;
            ret += tmp * tmp % mod * phi[i] % mod;
        }
        for(int i : a) cnt[i]--;
        return ret % mod;
    };
    ll ans = 0;
    for(int k = 1; k <= n; ++k) {
        vector<int> b;
        for(int i = k; i <= n; i += k) {
            b.push_back(a[i]);
        }
        ans += solve(b) * phi[k] % mod;
    }
    ans %= mod;
    cout << ans << '\n';
}