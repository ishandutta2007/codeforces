#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>
#include <map>

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

const int N=1000010;

typedef long long ll;

int n,p[N],a[N],hr[N]={0},hl[N]={0},bit[N]={0},top;
map <int,int> m;
void add(int idx,int v)
{
    while (idx<=n)
    {
        bit[idx]+=v;
        idx+=idx&-idx;
    }
}
int get(int idx)
{
    int tmp=0;
    while (idx)
    {
        tmp+=bit[idx];
        idx-=idx&-idx;
    }
    return tmp;
}
int main()
{
    ll ans=0;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    top=0;
    FORD(i,n,1)
    {
        if (m[a[i]]==0) m[a[i]]=++top;
        p[i]=++hr[m[a[i]]];
        add(p[i],1);
    }
    FOR(i,1,n)
    {
        add(p[i],-1);
        ans+=1LL*get(hl[m[a[i]]]);
        hl[m[a[i]]]++;
    }
    printf("%I64d",ans);
}