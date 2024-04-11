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
#define inf 1000000000

const int N=1010;

typedef long long ll;

int n,a,b,c;
ll s[N];
void check(ll a,int b)
{
    ll tmp=a;
    while (a)
    {
        b-=a%10;
        a/=10;
    }
    if (b==0) s[++s[0]]=tmp;
}
ll power(int a,int b)
{
    ll tmp=1;
    FOR(i,1,b) tmp*=a;
    return tmp;
}
void solve()
{
    for(int i=0;i<90;i++)
    {
        ll ans=power(i,a)*b+c;
        if (ans>=inf) break;
        //if (i<20) printf("%lld %d\n",ans,i);
        if (ans>0) check(ans,i);
    }
    printf("%lld\n",s[0]);
    FOR(i,1,s[0]) printf("%lld ",s[i]);
}
int main()
{
    cin>>a>>b>>c;
    solve();
}