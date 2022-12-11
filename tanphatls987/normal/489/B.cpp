#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,m,a[N],b[N],f[N][N]={0};
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",b+i);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    FOR(i,1,n)
        FOR(j,1,m){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if (abs(a[i]-b[j])<=1) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    cout<<f[n][m];
}