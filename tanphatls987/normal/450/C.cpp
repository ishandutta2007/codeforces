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

const int N=0;

typedef long long ll;

ll n,m,k;
int solve()
{
    ll ans=0;
    if (n<m) swap(n,m);
    if (k<m) ans=(m/(k+1))*n;
    if (k<n) ans=max(ans,(n/(k+1))*m);
    else
    {
        ans=max(ans,m/(k-n+2));
        ans=max(ans,n/(k-m+2));
    }
    cout<<ans;
}
int main()
{
    cin>>n>>m>>k;
    if (k>n+m-2) cout<<-1;
    else solve();
}