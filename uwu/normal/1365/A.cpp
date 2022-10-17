#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool grid[51][51];
bool row[51];
bool col[51];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r,c; cin >> r >> c;
        ms(grid,0);
        ms(row,0);
        ms(col,0);
        for (int i=1;i<=r;++i){
            for (int k=1;k<=c;++k){
                cin >> grid[i][k];
                if (grid[i][k]==1) row[i]=1,col[k]=1;
            }
        }
        bool win=0;
        for (int i=1;i<=r;++i){
            for (int k=1;k<=c;++k){
                if (!row[i]&&!col[k]){
                    row[i]=1; col[k]=1;
                    win=!win;
                }
            }
        }
        cout << (win?"Ashish":"Vivek") << '\n';

    }
}