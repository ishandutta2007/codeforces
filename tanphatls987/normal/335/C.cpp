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
const int N=1e2+10;

int f[3][N],h[300],n,m;
ii a[N];
int DP(int len,int side){
    if (f[side][len]!=-1) return f[side][len];
    memset(h,0,sizeof(h));
    f[side][len]=0;
    if (side==2){
        FOR(i,1,len) h[DP(i-1,2)^DP(len-i,0)]=1;
        REP(i,1,len) h[DP(i-1,2)^DP(len-i,1)]=1;
    }
    if (side==1) REP(i,1,len) h[DP(i-1,0)^DP(len-i,1)]=1;
    if (side==0){
        FOR(i,1,len) h[DP(i-1,0)^DP(len-i,0)]=1;
        REP(i,2,len) h[DP(i-1,1)^DP(len-i,1)]=1;
    }
    while (h[f[side][len]]) f[side][len]++;
    return f[side][len];
}
int spe(int len){
    memset(h,0,sizeof(h));
    FOR(i,1,len) h[DP(i-1,2)^DP(len-i,2)]=1;
    int ans=0;
    while (h[ans]) ans++;
    return ans;
}
int solve(){
    if (!n) return spe(m);
    int ans=0;
    FOR(i,2,n) ans^=DP(a[i].X-a[i-1].X-1,a[i].Y!=a[i-1].Y);
    ans^=DP(a[1].X-1,2)^DP(m-a[n].X,2);
    return ans;
}
void init(){
    memset(f,-1,sizeof(f));
    f[1][1]=0;
    f[0][0]=0;
    f[2][0]=0;
    FOR(len,1,m)
        FOR(side,0,2) DP(len,side);
}
int main(){
    memset(f,-1,sizeof(f));
    scanf("%d%d",&m,&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+n+1);
    init();
    if (solve()) printf("WIN\n");
    else printf("LOSE\n");
}