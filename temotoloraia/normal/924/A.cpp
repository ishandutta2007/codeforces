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
const int N = 55;
int n, m;
char ch[N][N];
bool F[N];
bool f1[N], f2[N];
void go2 (int c);
void go1 (int r){
    F[r] = 1;
    f1[r] = 1;
    for (int i = 1; i <= m; i++)
        if (ch[r][i] == '#' && f2[i] == 0)
            go2 (i);
}
void go2 (int c){
    f2[c] = 1;
    for (int i = 1; i <= n; i++)
        if (ch[i][c] == '#' && f1[i] == 0)
            go1 (i);
}
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin>>ch[i][j];
    for (int i = 1; i <= n; i++){
        if (F[i])
            continue;
        for (int a = 1; a <= n; a++)
            f1[a] = 0;
        for (int b = 1; b <= m; b++)
            f2[b] = 0;
        go1(i);
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= m; b++)
                if (ch[a][b] == '.' && f1[a] == 1 && f2[b] == 1){
                    cout<<"No\n";
                    return 0;
                }
    }
    cout<<"Yes\n";
    return 0;
}