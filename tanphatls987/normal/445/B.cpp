#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

typedef long long ll;

#define MOD 1000000007
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")

using namespace std;

const int maxd=52;

int n,m,a[maxd][maxd],x,y,h[maxd]={0},mem,top,tmp,s[100000]={0},flag=0;
int bigmul()
{
    mem=0;
    FOR(i,0,top)
    {
        tmp=s[i]*2+mem;
        s[i]=tmp%10;
        mem=tmp/10;
    }
    if (mem) {top++;s[top]=mem;}
}
int prepare()
{
    //INPUT;
    scanf("%d%d",&n,&m);
    FOR(i,1,m)
    {
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
}
int DFS(int x)
{
    h[x]=flag;
    FOR(i,1,n) if (a[x][i]==1&&h[i]==0) DFS(i);
}
int solve()
{
    FOR(i,1,n) if (h[i]==0)
    {
        flag++;
        DFS(i);
    }
    s[0]=1;
    top=0;
    FOR(i,1,n-flag) bigmul();
    for(int i=top;i>=0;i--) printf("%d",s[i]);
}
int main()
{
    prepare();
    solve();
}