#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")
#define inf 1000000

const int N=100010;

typedef long long ll;

int a[N]={0},s[N]={0},n,top;
int solve()
{
    s[0]=1;
    top=0;
    FOR(i,2,(n+1)) if (a[i]<=a[i-1]) s[++top]=i;
    int ans=0;
    FOR(i,1,top) ans=max(ans,s[i]-s[i-1]+1);
    FOR(i,1,top-1) if ((a[s[i]]>=a[s[i]-2]+2)||(a[s[i]+1]>=a[s[i]-1]+2)) ans=max(ans,s[i+1]-s[i-1]);
    printf("%d",min(ans,n));
}
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    solve();
}