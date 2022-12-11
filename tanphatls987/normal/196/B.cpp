#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=1510;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
typedef long long ll;
typedef pair<int,int> ii;

int n,m,k=0,flag,block[N][N]={0},h[N]={0};
ii st,d[N][N];
char s[N];
void prepare()
{
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
    {
        scanf("\n%s",s);
        FOR(j,1,m) switch(s[j-1])
        {
            case 'S':{st=ii(i,j);break;}
            case '#':{block[i][j]=1;break;}
        }
    }
    //FOR(i,0,n+1) {FOR(j,0,m+1) printf("%d ",block[i][j]);ENDL;}
}
void fix(int& a,int b)
{
    if (a>b) a%=b;
    if (a==0) a=b;
}
bool BFS()
{
    d[st.X][st.Y]=ii(0,0);
    queue <ii> q;
    q.push(ii(st.X,st.Y));
    while (!q.empty())
    {
        int cx=q.front().X,cy=q.front().Y;
        q.pop();
        FOR(i,0,3)
        {
            int nx=cx+dx[i],ny=cy+dy[i];
            fix(nx,n);fix(ny,m);
            if (block[nx][ny]) continue;
            if (d[nx][ny].X||d[nx][ny].Y)
            {
                if (d[cx][cy].X+dx[i]!=d[nx][ny].X||d[cx][cy].Y+dy[i]!=d[nx][ny].Y) return true;
                continue;
            }
            d[nx][ny]=ii(d[cx][cy].X+dx[i],d[cx][cy].Y+dy[i]);
            q.push(ii(nx,ny));
        }
    }
    return false;
}
void solve()
{
    if (BFS()) printf("Yes");else printf("No");
}
int main()
{
    prepare();
    solve();
}