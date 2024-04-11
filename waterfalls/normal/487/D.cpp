#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,q,counter;
char table[100013][13];
pair<int,int> go[100013][13];
int visited[100013][13];

const int SQRT = 300;

inline pair<int,int> dfs(int x, int y, int finish, int label) {
    if (x<finish || y==0 || y>m) return make_pair(x,y);
    if (visited[x][y]==label) return go[x][y];
    visited[x][y] = label;
    if (table[x][y]=='^') return go[x][y] = dfs(x-1,y,finish,label);
    if (table[x][y]=='<') return go[x][y] = dfs(x,y-1,finish,label);
    if (table[x][y]=='>') return go[x][y] = dfs(x,y+1,finish,label);
}

inline void solve(int start, int label) {
    int finish = max(1,start-SQRT+1);
    for (int i=finish;i<=start;i++) for (int j=1;j<m;j++) if (table[i][j]=='>' && table[i][j+1]=='<') {
        visited[i][j] = label; go[i][j] = make_pair(-1,-1);
        visited[i][j+1] = label; go[i][j+1] = make_pair(-1,-1);
    }
    for (int i=finish;i<=start;i++) for (int j=1;j<=m;j++) dfs(i,j,finish,label);
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++) scanf("%s",&table[i][1]);
    for (int i=0;i<=n+1;i++) table[i][0] = 'X', table[i][m+1] = 'X', table[i][m+2] = '\0';
    for (int j=0;j<=m+1;j++) table[0][j] = 'X', table[n+1][j] = 'X';
    counter = 1;
    for (int i=n;i>=1;i-=SQRT) solve(i,counter++);
    for (int Q=0;Q<q;Q++) {
        char type;
        scanf(" %c",&type);
        if (type=='C') {
            int x,y;
            char c;
            scanf("%d%d %c",&x,&y,&c);
            table[x][y] = c;
            while (x%SQRT!=n%SQRT) x+=1;
            solve(x,counter++);
        } else {
            int x,y;
            scanf("%d%d",&x,&y);
            pair<int,int> where = make_pair(x,y);
            while (where.first!=-1 && table[where.first][where.second]!='X') where = go[where.first][where.second];
            printf("%d %d\n",where.first,where.second);
        }
    }


    return 0;
}