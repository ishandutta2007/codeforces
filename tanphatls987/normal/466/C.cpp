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

const int N=500010;

typedef long long ll;

int a[N],n,s[N];
ll p=0;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) p+=a[i];
}
void solve()
{
    int top=0;
    ll sum=0,ans=0;
    FOR(i,1,n-2) {
        sum+=a[i];
        if (3*sum==p) s[++top]=i;
    }
    sum=0;
    FORD(i,n,3){
        while (s[top]+1>=i) top--;
        sum+=a[i];
        if (3*sum==p) ans+=top;
    }
    printf("%lld",ans);
}
int main()
{
    prepare();
    solve();
}