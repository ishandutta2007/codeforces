#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=301;

int ans[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        bool flag=true; int a;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if ((i==1||i==n)&&(j==1||j==m)) ans[i][j]=2;
                else if ((i==1||i==n)||(j==1||j==m)) ans[i][j]=3;
                else ans[i][j]=4;
                cin >> a;
                if (a>ans[i][j]) flag=false;
            }
        }
        if (flag==false) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for (int i=1;i<=n;++i){
                for (int j=1;j<=m;++j){
                    cout << ans[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }
}