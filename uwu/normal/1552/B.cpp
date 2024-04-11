#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e4+1;

int r[MAXN][5];

bool sup(int i, int j){
    int cnt=0;
    for (int x=0;x<5;++x) cnt+=r[i][x]<r[j][x];
    return cnt>=3;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            for (int j=0;j<5;++j){
                cin >> r[i][j];
            }
        }
        int cur=1;
        for (int i=2;i<=n;++i){
            if (sup(i,cur)) cur=i;
        }
        bool is=1;
        for (int i=1;i<=n;++i){
            if (i==cur) continue;
            is&=sup(cur,i);
        }
        if (is) cout << cur << '\n';
        else cout << -1 << '\n';
    }
}