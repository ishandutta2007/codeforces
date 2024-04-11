#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=155;

int f[2][N][N*N],n,m,k,a[N];
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    k=min(k,n*n);
    FOR(i,1,n) scanf("%d",a+i);
}
int solve(){
    int cur=0,last=1;
    FOR(i,1,n) {
        swap(cur,last);
        FOR(j,0,min(i,m)){
//            cout<<i<<" "<<j<<'\n';
            FOR(use,0,k){
                f[cur][j][use]=inf;
                if (j<i) minimize(f[cur][j][use],f[last][j][use]);

                if (use) minimize(f[cur][j][use],f[cur][j][use-1]);
                if (j&&use>=i-j) minimize(f[cur][j][use],f[last][j-1][use-(i-j)]+a[i]);
//                printf("%d %d %d %d %d\n",i,j,use,f[cur][j][use]);
        }
        }
    }
    return f[cur][m][k];
}
int main(){
    prepare();
    cout<<solve();
}