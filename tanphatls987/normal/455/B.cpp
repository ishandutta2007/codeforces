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

const int N=100010;

typedef long long ll;
int c[N][26],lose[N]={0},win[N]={0},n,k,m;
char s[N];

void add(char* s)
{
    int v=0;
    for(int i=0;s[i];v=c[v][s[i++]-'a']) if (!c[v][s[i]-'a']) c[v][s[i]-'a']=++m;
}
void prepare()
{
    scanf("%d%d",&n,&k);
    FOR(i,1,n)
    {
        scanf("\n%s",s);
        add(s);
    }
}
void DFS(int x)
{
    if (count(c[x],c[x]+26,0)==26)
    {
        lose[x]=1;
        win[x]=0;
        return;
    }
    REP(i,0,26) if (c[x][i])
    {
        DFS(c[x][i]);
        win[x]=win[x]||(!win[c[x][i]]);
        lose[x]=lose[x]||(!lose[c[x][i]]);
    }
}
int main()
{
    prepare();
    DFS(0);
    if (win[0]==0) printf("Second");
    else
    {
        if (lose[0]==1) printf("First");
        else {if (k%2) printf("First");else printf("Second");}
    }
}