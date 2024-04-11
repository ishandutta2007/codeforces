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

const ll inf=1e16;
const int MOD=1e9+7;
const int N=3e2+10;

int t[3],a[N][N],n,m,p[N],b[N];
ll V,f[4][N][N],ma[N];
int cv(int x,int y){
    if (x==y) return t[0];
    return (x>y)?t[2]:t[1];
}
void prepare(){
    FOR(i,1,n)
        FOR(j,1,m){
            f[0][i][j]=f[0][i][j-1]+cv(a[i][j-1],a[i][j]);
            f[1][i][j]=f[1][i][j-1]+cv(a[i][j],a[i][j-1]);
            f[2][i][j]=f[2][i-1][j]+cv(a[i-1][j],a[i][j]);
            f[3][i][j]=f[3][i-1][j]+cv(a[i][j],a[i-1][j]);
        }
}
void add(int x,int v,int n){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int findfre(int v,int n){
    int pos=0,ans=-1;
    if (v==0) return -1;
    for(int i=1<<int(log2(n));i>0;i>>=1){
        int cur=pos+i;
        if (cur<=n){
            if (b[cur]<v) v-=b[cur],pos=cur;
            else ans=cur;
        }
    }
    return ans;
}
bool minimize(ll &x,ll y){
    if (x>y) x=y;else return false;
    return true;
}
void solve(){
    prepare();
    int r1,r2,c1,c2;
    ll ans=inf;
    FOR(up,1,n)
        FOR(down,up+2,n){
            FOR(j,3,m) ma[j-2]=f[0][up][j]+f[1][down][j]+f[2][down][j]-f[2][up][j];
            sort(ma+1,ma+m-1);
            int m1=unique(ma+1,ma+m-1)-ma-1;
            memset(b,0,sizeof(b));
            FOR(j,3,m) {
                p[j]=lower_bound(ma+1,ma+m1+1,f[0][up][j]+f[1][down][j]+f[2][down][j]-f[2][up][j])-ma;
                add(p[j],1,m1);
            }
            FOR(j,1,m-2){
                ll cval=-f[0][up][j]-f[1][down][j]+f[3][down][j]-f[3][up][j],expv=V-cval;
                int pos=upper_bound(ma+1,ma+m1+1,expv)-ma-1,c=get(pos);
                FOR(k,0,1){
                    int p1=findfre(c+k,m1);
                    if (p1!=-1&&minimize(ans,abs(V-(ma[p1]+cval)))) r1=up,r2=down,c1=j;
                }
                add(p[j+2],-1,m1);
            }
        }
    FOR(j,c1+2,m) if (abs(V-(f[0][r1][j]-f[0][r1][c1]+f[2][r2][j]-f[2][r1][j]+f[1][r2][j]-f[1][r2][c1]+f[3][r2][c1]-f[3][r1][c1]))==ans) c2=j;
    printf("%d %d %d %d",r1,c1,r2,c2);
}
int main(){
//    INPUT;
    scanf("%d%d%I64d",&n,&m,&V);
    FOR(i,0,2) scanf("%d",t+i);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",&a[i][j]);
    solve();
}