#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 20000005;
int prime[maxn],np[maxn],mp[maxn],pc[maxn],tot=0;
void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i, mp[i] = i, pc[i] = 1;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           mp[i*prime[j]] = prime[j];
           pc[i*prime[j]] = pc[i];
           if(mp[i]!=prime[j]) pc[i*prime[j]]++;
           if(i%prime[j]==0) break;
       }
   }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(maxn - 1);
    int t;
    cin >> t;
    while(t--) {
        ll c, d, x;
        cin >> c >> d >> x;
        ll ans = 0;
        auto calc = [&](int g) {
            if((x + d * g) % c) return 0;
            ll l = (x + d * g) / c;
            if(l % g) return 0;
            l /= g;
            assert(l < maxn);
            return 1 << pc[l];
        };
        for(int i = 1; i * i <= x; ++i) {
            if(x % i == 0) {
                ans += calc(i);
                if(i * i != x) ans += calc(x / i);
            }
        }
        cout << ans << endl;
    }
}