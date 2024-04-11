#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=510;

char grid[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c,tot=0; cin >> r >> c;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> grid[i][j];
            tot+=grid[i][j]=='*';
        }
    }
    bool flag=0;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            if (grid[i][j]!='*') continue;
            int cnt=1; int a=0,b=0,c=0,d=0;
            for (int x=i+1;grid[x][j]=='*';++x) a=1,cnt++;
            for (int x=i-1;grid[x][j]=='*';--x) b=1,cnt++;
            for (int y=j+1;grid[i][y]=='*';++y) c=1,cnt++;
            for (int y=j-1;grid[i][y]=='*';--y) d=1,cnt++;
            if (cnt==tot&&a+b+c+d==4) flag=1;
        }
    }
    cout << (flag?"YES":"NO") << '\n';
}