#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const ll N = 1234;

int n, m;
char ch[N][N];

int D[5][N][N];

bool F[N][N];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void dfs (int r, int c){
    F[r][c] = 1;
    for (int i = 0; i < 4; i++){
        int newr = r + dr[i];
        int newc = c + dc[i];
        if (newr < 1 || n < newr || newc < 1 || m < newc)
            continue;
        if (F[newr][newc] == 1 || ch[newr][newc] == '#' || ch[newr][newc] == '.')
            continue;
        ch[newr][newc] = ch[r][c];
        dfs (newr, newc);
    }
}

queue < int > Qx, Qy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ch[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (F[i][j] == 0 && '1' <= ch[i][j] && ch[i][j] <= '3')
                dfs (i, j);
    for (int I = 1; I <= 3; I++){
        while ((int)Qx.size() > 0){
            Qx.pop();
            Qy.pop();
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (ch[i][j] == I + '0'){
                    Qx.push (i);
                    Qy.push (j);
                }
        if ((int)Qx.size() == 0)
            continue;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (ch[i][j] != I + '0')
                    D[I][i][j] = 1e8;
        while ((int)Qx.size() > 0){
            int r = Qx.front(), c = Qy.front();
            Qx.pop();
            Qy.pop();
            for (int i = 0; i < 4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                int t = 1;
                if (ch[r][c] == ch[newr][newc] && '1' <= ch[r][c] && ch[r][c] <= '3')
                    t = 0;
                if (ch[newr][newc] == '#' || D[I][newr][newc] <= D[I][r][c] + t)
                    continue;
                D[I][newr][newc] = D[I][r][c] + t;
                Qx.push (newr);
                Qy.push (newc);
            }
        }
    }
    int ans = 1e7;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            int t = 0;
            if (ch[i][j] < '0' || '3' < ch[i][j])
                t = 1;
            for (int l = 1; l <= 3; l++)
                t += max (0, D[l][i][j] - 1);
            ans = min (ans, t);
        }
    if (ans == 1e7)
        ans = -1;
    cout << ans << endl;
    return 0;
}