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
const ll MOD=1e9+7;
const int N=5e3+10;

ll f[2][N]={0};
int n,k,x,y;
int main(){
    scanf("%d%d%d%d",&n,&x,&y,&k);
    for(int i=x;i<=n;i++) f[0][i]=1;
    FOR(i,1,k){
        int next=i%2,last=(i+1)%2;
        memset(f[next],0,sizeof(f[next]));
        FOR(j,1,n){
            f[next][j]=f[next][j-1];
            if (j<y) f[next][j]=(f[next][j]+f[last][(j+y-1)/2]+f[last][j-1]-f[last][j]+4*MOD)%MOD;
            else if (j>y) f[next][j]=(f[next][j]+f[last][n]-f[last][j]+f[last][j-1]-f[last][(j+y)/2]+4*MOD)%MOD;
        }
    }
    cout<<f[k%2][n];
}