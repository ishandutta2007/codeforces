#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

int g[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int odd=0, even=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                char a; cin >> a;
                if (a=='.') g[i][j]=0;
                if (a=='R') g[i][j]=1;
                if (a=='W') g[i][j]=-1;
                if (g[i][j]==0) continue;
                if ((i+j)%2==0) even=g[i][j];
                else odd=g[i][j];
            }
        }
        if (odd==0&&even==0) odd=-1, even=1;
        else if (even){
            odd=-even;
        } 
        else{
            even=-odd;
        }
        if (even==odd){ cout << "NO" << '\n'; continue; }
        bool can=1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if ((i+j)%2==0){
                    if (g[i][j]&&g[i][j]!=even) can=0;
                    g[i][j]=even;
                }
                else{
                    if (g[i][j]&&g[i][j]!=odd) can=0;
                    g[i][j]=odd;
                }
            }
        }
        if (!can) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for (int i=1;i<=n;++i){
                for (int j=1;j<=m;++j){
                    if (g[i][j]==-1) cout << 'W';
                    else cout << 'R';
                }
                cout << '\n';
            }
        }
    }
}