#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=5e2+10;

int n,m,k,a[N][N],b[N][N],pd[N][N],pu[N][N],zone[N<<1][N<<1];
ll cd[N][N],cu[N][N];
vector <int> d,res;
int comp(int x,int y){
    if (x>y) return 1;
    if (x<y) return -1;
    return 0;
}
void optimize(int &cx,ll &cv,int nx,ll nv){
    int deci=comp(nx,cx);
    if (deci>=0) {
        cx=nx;
        if (deci) cv=nv;
        else cv+=nv;
    }
}
int sum(int row,int L,int R){
    if (row>n||row<=0) return 0;
    L=max(L,1);R=min(m,R);
    return a[row][R]-a[row][L-1];
}
void findzone(){
    FOR(nx,0,k){
        int ny=d[nx];
        FOR(ia,0,k)
            for(int sa1=-1;sa1<=1;sa1+=2){
                int nax=nx+sa1*ia;
                zone[nax][ny+d[ia]]=1;
            }
    }
    FOR(i,0,k<<1){
        int R=(k<<1);
        while (R>=0&&!zone[i][R]) R--;
        res.push_back(R);
    }
}
void prepare(){
    FOR(i,0,k) d.push_back(int(sqrt(k*k-i*i)));
    findzone();
//    FOR(i,0,k) cout<<d[i]<<" \n"[i==k];
//    FOR(i,0,k<<1) cout<<res[i]<<" \n"[i==2*k];
    FOR(i,1,n)
        FOR(j,1,m) a[i][j]+=a[i][j-1];
    FOR(i,k+1,n-k)
        FOR(j,k+1,m-k)
            FOR(i1,0,k) {
                b[i][j]+=sum(i+i1,j-d[i1],j+d[i1]);
                if (i1) b[i][j]+=sum(i-i1,j-d[i1],j+d[i1]);
            }
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<b[i][j]<<" \n"[j==m];
    FOR(i,k+1,n-k)
        FOR(j,k+1,m-k) pd[i][j]=pu[i][j]=b[i][j];
    FOR(i,k+1,n-k)
        FOR(j,k+1,m-k) cd[i][j]=cu[i][j]=1;
    FOR(j,k+1,m-k)
        FOR(i,k+1,n-k) optimize(pd[i][j],cd[i][j],pd[i-1][j],cd[i-1][j]);
    FOR(j,k+1,m-k)
        FORD(i,n-k,k+1) optimize(pu[i][j],cu[i][j],pu[i+1][j],cu[i+1][j]);

//    FOR(i,k+1,n-k)
//        FOR(j,k+1,m-k) cout<<pd[i][j]<<" \n"[j==m-k];
}
void solve(){
    int ans=0;
    ll cter=0;
    FOR(cx,k+1,n-k)
        FOR(cy,k+1,m-k){
            REP(j,k+1,cy-k*2) optimize(ans,cter,b[cx][cy]+pd[n-k][j],cd[n-k][j]);
            FOR(j,cy+k*2+1,m-k) optimize(ans,cter,b[cx][cy]+pd[n-k][j],cd[n-k][j]);
            FOR(j,0,k<<1){
                for(int s1=-1;s1<=1;s1+=2){
                    int ny=cy+j*s1;
                    if (s1==1&&!j) continue;
                    if (ny>m-k||ny<=k) continue;
                    if (cx-res[j]-1>k) optimize(ans,cter,b[cx][cy]+pd[cx-res[j]-1][ny],cd[cx-res[j]-1][ny]);
                    if (cx+res[j]+1<=n-k) optimize(ans,cter,b[cx][cy]+pu[cx+res[j]+1][ny],cu[cx+res[j]+1][ny]);
                }
            }
//            cout<<cx<<" "<<cy<<" "<<ans<<" "<<cter<<'\n';
        }
    cout<<ans<<" "<<cter/2;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",a[i]+j);
    if (2*k>=min(n,m)){
        printf("0 0");
        return 0;
    }
    //
    prepare();
    solve();
}