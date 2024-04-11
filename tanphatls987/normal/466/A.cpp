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

const int N=0;

typedef long long ll;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans=10000000;
    for(int i=0;i<=(n+m-1)/m;i++){
        ans=min(ans,i*b+((i*m<=n)?(n-m*i)*a:0));
    }
    cout<<ans;
}