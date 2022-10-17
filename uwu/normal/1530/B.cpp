#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=21;

bool g[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        ms(g,0);
        g[1][1]=g[1][m]=g[n][1]=g[n][m]=1;
        for (int i=3;i<m-1;i+=2) g[1][i]=g[n][i]=1;
        for (int i=3;i<n-1;i+=2) g[i][1]=g[i][m]=1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cout << g[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}