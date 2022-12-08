#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1000005;
int prime[maxn],np[maxn],a[maxn],tot=0;
void init(int n) {
   a[1]=np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i, a[i] = 2;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>=maxn) break;
           a[i*prime[j]] = a[i] * 2;
           np[i*prime[j]] = 1;
           if(i%prime[j]==0) {
               int cnt = 0;
               int x = i;
               while(x % prime[j] == 0) x /= prime[j], ++cnt;
               a[i*prime[j]] = a[i] / (cnt + 1) * (cnt + 2);
               break;
           }
       }
   }
}

const int mod = 998244353;
int main() {
    int n;
    cin >> n;
    init(n);
    ll ans = 1;
    for(int i=1;i<n;++i) {
        ans = (ans * 2 + a[i+1] - a[i]) % mod;
    }
    if(ans < 0) ans += mod;
    cout << ans << endl;
}