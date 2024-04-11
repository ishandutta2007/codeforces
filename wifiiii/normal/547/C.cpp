#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
int cnt[maxn];
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
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(maxn - 1);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n, -1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    while(q--) {
        int x;
        cin >> x;
        --x;
        b[x] = -b[x];
        if(b[x] == 1) {
            for(int j = 1; j * j <= a[x]; ++j) {
                if(a[x] % j == 0) {
                    ans += mu[j] * cnt[j];
                    cnt[j] += 1;
                    if(j * j != a[x]) {
                        ans += mu[a[x] / j] * cnt[a[x] / j];
                        cnt[a[x] / j] += 1;
                    }
                }
            }
        } else {
            for(int j = 1; j * j <= a[x]; ++j) {
                if(a[x] % j == 0) {
                    cnt[j] -= 1;
                    ans -= mu[j] * cnt[j];
                    if(j * j != a[x]) {
                        cnt[a[x] / j] -= 1;
                        ans -= mu[a[x] / j] * cnt[a[x] / j];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}