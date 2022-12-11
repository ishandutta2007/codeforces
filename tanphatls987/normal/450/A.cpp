#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

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

const int N=110;

typedef long long ll;

int n,m,a[N],ans;
int main()
{
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    ans=1;
    FOR(i,1,n) if (((a[i]+m-1)/m)>=((a[ans]+m-1)/m)) ans=i;
    cout<<ans;
}