#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("301.inp","r",stdin)
#define OUTPUT freopen("301.out","w",stdout)
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
const int N=2e5+10;

int b[N],n,p[N],pos[N],cur[N],m;
ii e[N];
int get(int x){
    int tmp=0;
    while (x){
        tmp+=b[x];
        x-=x&-x;
    }
    return tmp;
}
void add(int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&e[i].X,&e[i].Y);
    FOR(i,1,n) p[i]=e[i].X,p[n+i]=e[i].Y;
    sort(p+1,p+2*n+1);
    m=unique(p+1,p+2*n+1)-p-1;
    FOR(i,1,m) cur[i]=i;
    FOR(i,1,n){
        int x=lower_bound(p+1,p+m+1,e[i].X)-p,y=lower_bound(p+1,p+m+1,e[i].Y)-p;
        swap(cur[x],cur[y]);
    }
    FOR(i,1,m) pos[cur[i]]=i;
    ll ans=0;
    FOR(i,1,m){
        int lat=pos[i];
        if (lat<i) ans+=p[i]-p[lat]-(i-lat);
        else ans+=p[lat]-p[i]-(lat-i);
    }
    //FOR(i,1,m) cout<<p[cur[i]]<<" \n"[i==m];
    FORD(i,m,1){
        ans+=get(cur[i]);
        add(cur[i],1);
    }
    cout<<ans;
}