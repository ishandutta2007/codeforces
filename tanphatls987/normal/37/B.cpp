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

const int N=2010;

typedef long long ll;
typedef pair<int,int> ii;
struct scroll{int per,dam,st;}a[N];

int n,ihp,regen,time=0;
vector <ii> ans;
bool comp(scroll x,scroll y){return x.per>y.per;}
void prepare()
{
    scanf("%d%d%d",&n,&ihp,&regen);
    FOR(i,1,n) scanf("%d%d",&a[i].per,&a[i].dam);
    FOR(i,1,n) a[i].st=i;
    sort(a+1,a+n+1,comp);
}
void result()
{
    printf("YES\n%d %d\n",time,ans.size());
    REP(i,0,ans.size()) printf("%d %d\n",ans[i].X,ans[i].Y);
}
void solve()
{
    int dps=0,i=1,hp=ihp;
    priority_queue <ii> scr;
    while (1)
    {
        hp=hp-dps+regen;
        if (hp<=0) {result();return;}
        if (hp>ihp) hp=ihp;
        while (i<=n&&a[i].per*ihp>=hp*100) {scr.push(ii(a[i].dam,a[i].st));i++;}
        if (scr.empty()){
            if (dps<=regen) {printf("NO");return;}
        }else
        {
            dps+=scr.top().X;
            ans.push_back(ii(time,scr.top().Y));
            scr.pop();
        }
        time++;
    }
}
int main()
{
    prepare();
    solve();
}