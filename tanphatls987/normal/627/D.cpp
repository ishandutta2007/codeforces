#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e6+10;
const int MOD=1e9+7;
const int N=2e5+10;

int n,k,q[N],pa[N];
int a[N];
vector <int> v[N];
struct info{
    int v,allsub;
    info (int _v=0,int _allsub=0){
        v=_v;allsub=_allsub;
    }
};
info f[N],fpa[N];
int sgood[2][N],sbest[2][N],sall[2][N];
void BFS(){
    q[1]=1;
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=pa[x]){
            pa[y]=x;
            q[++bot]=y;
        }
    }
}
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int x,y;
    REP(i,1,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
}
bool check(int mid){
    ///phase bottom up
//    cout<<mid<<'\n';
    FORD(pha,n,1){
        int x=q[pha];
        ///bad vertex
        if (a[x]<mid) {
            f[x]=info(0,0);
            continue;
        }
        int n1=v[x].size();
        int csub=0,best=0,can=0;
        REP(i,0,n1) if (v[x][i]!=pa[x]){
            int y=v[x][i];
            if (f[y].allsub) {
                can+=f[y].v;
                csub++;
            }else best=max(best,f[y].v);
        }
        if (csub==n1-(pa[x]>0)) f[x]=info(can+1,1);
        else f[x]=info(can+1+best,0);
//        cout<<x<<" "<<f[x].allsub<<" "<<f[x].v<<'\n';
    }
    ///phase top down
    FOR(pha,1,n){
        int x=q[pha];
        int n1=v[x].size();
        ///reset
        ///bad vertex
        if (a[x]<mid){
            for(auto y:v[x]) if (y!=pa[x]) fpa[y]=info(0,0);
            continue;
        }
        FOR(i,0,1){
            fill(sgood[i],sgood[i]+n1+2,0);
            fill(sbest[i],sbest[i]+n1+2,0);
            fill(sall[i],sall[i]+n1+2,0);
        }
        FOR(i,1,n1){
            int y=v[x][i-1];
            info cur=(y==pa[x])?fpa[x]:f[y];
            if (cur.allsub) {
                sgood[0][i]=sgood[1][i]=cur.v;
                sall[0][i]=sall[1][i]=1;
            }else sbest[0][i]=sbest[1][i]=cur.v;
        }
        FOR(i,1,n1) {
            sgood[0][i]+=sgood[0][i-1];
            sall[0][i]+=sall[0][i-1];
        }
        FORD(i,n1,1) {
            sgood[1][i]+=sgood[1][i+1];
            sall[1][i]+=sall[1][i+1];
        }
        FOR(i,1,n1) sbest[0][i]=max(sbest[0][i],sbest[0][i-1]);
        FORD(i,n1,1) sbest[1][i]=max(sbest[1][i],sbest[1][i+1]);
        if (sgood[0][n1]+sbest[0][n1]+1>=k) return 1;
        FOR(i,1,n1){
            int y=v[x][i-1];
            if (y==pa[x]) continue;
            int call=sall[0][i-1]+sall[1][i+1],can=sgood[0][i-1]+sgood[1][i+1],best=max(sbest[0][i-1],sbest[1][i+1]);
            if (call==n1-1) fpa[y]=info(can+1,1);
            else fpa[y]=info(can+1+best,0);
        }
    }
    return 0;
}
int solve(){
    int L=1,R=inf;
    while (L<=R){
        int mid=(L+R)/2;
        if (check(mid)) L=mid+1;
        else R=mid-1;
    }
    return R;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}