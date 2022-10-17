#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=52;

char arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int r,c;

bool in(int row, int col){
    return (row>0&&row<=r&&col>0&&col<=c);
}

void can(){
    int row=r,col=c;
    queue<pii> q; q.push({row,col}); vis[row][col]=1;
    int x,y;
    while (!q.empty()){
        x=q.front().f,y=q.front().s; q.pop();
        if (!in(x,y)) continue;
        
        if (arr[x+1][y]!='#'&&!vis[x+1][y]) vis[x+1][y]=1, q.push({x+1,y});
        if (arr[x-1][y]!='#'&&!vis[x-1][y]) vis[x-1][y]=1, q.push({x-1,y});
        if (arr[x][y+1]!='#'&&!vis[x][y+1]) vis[x][y+1]=1, q.push({x,y+1});
        if (arr[x][y-1]!='#'&&!vis[x][y-1]) vis[x][y-1]=1, q.push({x,y-1});
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> r >> c;
        for (int i=1;i<=51;++i){
            for (int k=1;k<=51;++k){
                arr[i][k]='.';
            }
        }
        for (int i=1;i<=r;++i){
            for (int k=1;k<=c;++k){
                cin >> arr[i][k];
            }
        }
        bool flag=true;
        char uwu;
        for (int i=1;i<=r;++i){
            for (int k=1;k<=c;++k){
                if (arr[i][k]=='B'){
                    if (arr[i+1][k]=='G'||arr[i-1][k]=='G'||arr[i][k+1]=='G'||arr[i][k-1]=='G') flag=false;
                    if (arr[i+1][k]!='B') arr[i+1][k]='#';
                    if (arr[i-1][k]!='B') arr[i-1][k]='#';
                    if (arr[i][k+1]!='B') arr[i][k+1]='#';
                    if (arr[i][k-1]!='B') arr[i][k-1]='#';
                }
            }
        }
        ms(vis,0);
        if (arr[r][c]!='#') can();
        for (int i=1;i<=r;++i){
            for (int k=1;k<=c;++k){
                if (arr[i][k]=='G') flag&=vis[i][k];
            }
        }
        if (!flag) cout << "no" << '\n';
        else cout << "yes" << '\n';

    }    
}