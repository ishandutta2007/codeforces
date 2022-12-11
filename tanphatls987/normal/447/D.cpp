#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <queue>

using namespace std;

#define MOD 1000000007
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")
#define inf 1000010

const int N=1010;

typedef long long ll;

int tmp,n,m,p,k;
ll r[N]={0},c[N]={0},ci[inf]={0},ri[inf]={0};
int prepare()
{
    //INPUT;
    scanf("%d%d%d%d",&n,&m,&k,&p);
    FOR(i,1,n) FOR(j,1,m)
    {
        scanf("%d",&tmp);
        r[i]+=tmp;
        c[j]+=tmp;
    }
}
int solve()
{
    priority_queue <int> cheap,rheap;
    FOR(i,1,m) cheap.push(c[i]);
    FOR(i,1,n) rheap.push(r[i]);
    FOR(i,1,k)
    {
        int tmp=cheap.top();
        ci[i]=tmp+ci[i-1];
        cheap.pop();cheap.push(tmp-n*p);
        tmp=rheap.top();
        ri[i]=tmp+ri[i-1];
        rheap.pop();rheap.push(tmp-m*p);
    }
    ll ans=-1000000000000000000;
    FOR(i,0,k) ans=max(ans,ci[i]+ri[k-i]-(1LL*i*(k-i)*p));
    cout<<ans;
}
int main()
{
    prepare();
    solve();
}