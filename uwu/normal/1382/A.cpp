#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        bool vis[1001]={0};
        int ans=-1;
        for (int i=1,a;i<=n;++i) cin >> a, vis[a]=1;
        for (int i=1,b;i<=m;++i){
            cin >> b;
            if (vis[b]) ans=b;
        }
        if (ans==-1) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n' << 1 << " " << ans << '\n';
        }
    }
}