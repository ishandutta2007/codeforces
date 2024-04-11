#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=505;

bool last[MAXN][MAXN], curr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(last, 0), ms(curr, 0);
        int n, m, ans=0; cin >> n >> m;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                char a; cin >> a;
                if (a=='*') curr[i][j]=1, ans++;
            }
        }
        for (int cnt=0;cnt<=n;++cnt){
            swap(last,curr);
            for (int i=1;i<=n;++i){
                for (int j=1;j<=m;++j){
                    if (last[i-1][j]&&last[i][j-1]&&last[i][j+1]&&last[i][j]) curr[i][j]=1, ans++;
                    else curr[i][j]=0;
                }
            }
        }
        cout << ans << '\n';
    }
}