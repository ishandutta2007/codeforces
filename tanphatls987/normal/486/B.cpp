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

int n,m,h[N][N]={0},a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]==0){
            FOR(k,1,n) h[k][j]=1;
            FOR(k,1,m) h[i][k]=1;
        }
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]){
            int tmp=0;
            FOR(k,1,m) tmp+=h[i][k]==0;
            FOR(k,1,n) tmp+=h[k][j]==0;
            if (tmp==0) {printf("NO");return 0;}
        }
    printf("YES\n");
    FOR(i,1,n){
        FOR(j,1,m) printf("%d ",1-h[i][j]);ENDL;
    }
}