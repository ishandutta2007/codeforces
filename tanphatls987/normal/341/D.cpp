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
const int N=1e3+5;

int n,m,type,xa,xb,ya,yb;
ll a[N][N],b[4][N][N],v;
ii si[4];
void updatey(int type,int x,int y,ll v){
    while (y<=si[type].Y){
        b[type][x][y]^=v;
        y+=y&-y;
    }
}
void updatex(int type,int x,int y,ll v){
    while (x<=si[type].X){
        updatey(type,x,y,v);
        x+=x&-x;
    }
}
ll gety(int type,int x,int y){
    ll ans=0;
    while (y){
        ans^=b[type][x][y];
        y-=y&-y;
    }
    return ans;
}
ll getx(int type,int x,int y){
    ll ans=0;
    while (x){
        ans^=gety(type,x,y);
        x-=x&-x;
    }
    return ans;
}

void update(int xa,int ya,ll v){
    updatex(xa%2*2+ya%2,(xa+1)/2,(ya+1)/2,v);
//    FOR(i,1,si[sel].X)
//        FOR(j,1,si[sel].Y) cout<<getx(sel,i,j)<<" \n"[j==si[sel].Y];
}
void init(){
    int n0=n/2,n1=(n+1)/2;
    //printf("tick\n");
    si[0]=ii(n0,n0);
    si[1]=ii(n0,n1);
    si[2]=ii(n1,n0);
    si[3]=ii(n1,n1);
}
ll get(int x,int y){
    int sel=x%2*2+y%2;
//    printf("%d %d %I64d\n",x,y,getx(sel,(x+1)/2,(y+1)/2));
    return getx(sel,(x+1)/2,(y+1)/2);

}
int main(){
    scanf("%d%d",&n,&m);
    init();
    while (m--){
        scanf("%d%d%d%d%d",&type,&xa,&ya,&xb,&yb);
        if (type==2){
            scanf("%I64d",&v);
            update(xa,ya,v);
            update(xa,yb+1,v);
            update(xb+1,ya,v);
            update(xb+1,yb+1,v);
//            FOR(i,1,n)
//                FOR(j,1,n) cout<<getx((i%2*2+j%2),i,j)<<" \n"[j==n];
        }else printf("%I64d\n",get(xb,yb)^get(xa-1,ya-1)^get(xa-1,yb)^get(xb,ya-1));

    }
}