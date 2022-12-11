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
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int MOD=1000000007;
const int N=1010;

typedef long long ll;

int n,k,m,a[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m+1) scanf("%d",&a[i]);
}
int main()
{
    prepare();
    int ans=0;
    FOR(i,1,m){
        int c=0;
        REP(j,0,n) c+=((a[i]&(1<<j))!=(a[m+1]&(1<<j)));
        ans+=c<=k;
    }
    printf("%d",ans);
}