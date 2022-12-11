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

const int N=300010;

typedef long long ll;
typedef pair<int,int> ii;

int h[N]={0},f[N],avail[N]={0},n,x,y,k,q,m;
vector <int> a[N];
int BFS1(int st)
{
    h[st]=-1;
    queue <int> q;
    q.push(st);
    while (1)
    {
        int cur=q.front();q.pop();
        REP(i,0,a[cur].size()) if (!h[a[cur][i]]) {h[a[cur][i]]=st;h[st]--;q.push(a[cur][i]);}
        if (q.empty()) return cur;
    }
}
void BFS2(int st)
{
    queue <ii> q;
    q.push(ii(st,0));
    avail[st]=1;
    while (!q.empty())
    {
        ii cur=q.front();q.pop();
        REP(i,0,a[cur.X].size()) if (!avail[a[cur.X][i]]) {avail[a[cur.X][i]]=1;q.push(ii(a[cur.X][i],cur.Y+1));}
        if (q.empty()) f[h[st]]=cur.Y;
    }
}
void prepare()
{
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,m) scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
    FOR(i,1,n) if (h[i]==0) BFS2(BFS1(i));
}
int find_root(int x)
{
    while (h[x]>0) x=h[x];
    return x;
}
void merge_root(int x,int y)
{
    x=find_root(x);y=find_root(y);
    if (x==y) return;
    if (h[x]<h[y])
    {
        h[x]+=h[y];
        h[y]=x;
        f[x]=max(f[x],max(f[y],(f[x]+1)/2+(f[y]+1)/2+1));
    }else
    {
        h[y]+=h[x];
        h[x]=y;
        f[y]=max(f[x],max(f[y],(f[x]+1)/2+(f[y]+1)/2+1));
    }
}
int main()
{
    prepare();
    while (q--)
    {
        scanf("%d%d",&k,&x);
        if (k==1) printf("%d\n",f[find_root(x)]);
        else
        {
            scanf("%d",&y);
            merge_root(x,y);
        }
    }
}