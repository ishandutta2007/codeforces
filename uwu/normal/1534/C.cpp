#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e5+1;

int a[MAXN], b[MAXN], pa[MAXN], pb[MAXN];
bool vis[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            a[i]=x;
            pa[x]=i;
        }
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            b[i]=x;
            pb[x]=i;
        }
        for (int i=1;i<=n;++i) vis[i]=0;
        int ans=1;
        for (int i=1;i<=n;++i){
            if (vis[i]) continue;
            int idx=i;
            while (true){
                vis[idx]=1;
                idx=pa[b[idx]];
                if (idx==i) break;
            }
            ans=ans*2%mod;
        }
        for (int i=1;i<=n;++i) if (a[i]==b[i]) ans=0;
        cout << ans << '\n';
    }
}