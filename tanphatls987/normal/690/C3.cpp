#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c3.inp","r",stdin)
#define OUTPUT freopen("c3.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,pa[N][20],lv[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,2,n) scanf("%d",pa[i]);
    FOR(i,2,n) lv[i]=lv[pa[i][0]]+1;
    FOR(lay,1,19)
        FOR(i,1,n) pa[i][lay]=pa[pa[i][lay-1]][lay-1];
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,val=lv[x]-lv[y];val;i++,val>>=1)
        if (val&1) x=pa[x][i];
    if (x==y) return x;
    for(int i=int(log2(lv[x]));i>=0;i--) if (pa[x][i]!=pa[y][i])
        x=pa[x][i],y=pa[y][i];
    return pa[x][0];
}
int dist(int x,int y){
    return lv[x]+lv[y]-2*lv[LCA(x,y)];
}
void solve(){
    int s1=1,s2=1;
    FOR(i,2,n){
        int ds1=dist(i,s1),ds2=dist(i,s2);
        if (max(ds1,ds2)>dist(s1,s2)){
            if (ds1>ds2) s2=i;
            else s1=i;
        }
        printf("%d ",dist(s1,s2));
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}