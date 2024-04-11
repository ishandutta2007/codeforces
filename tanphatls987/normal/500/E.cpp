#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,pos[N],w[N],c[N][20],q,x,y,m,t[N][20],b[N];

void update(int x,int v){
    while (x<=n){
        b[x]=max(b[x],v);
        x+=x&-x;
    }
}
int get(int x){
    int tmp=-inf;
    while (x){
        tmp=max(tmp,b[x]);
        x-=x&-x;
    }
    return tmp;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&pos[i],&w[i]);
    t[n][0]=n+1,c[n][0]=0;
    FORD(i,n-1,1){
        int R=upper_bound(pos+1,pos+n+1,pos[i]+w[i])-pos-1,re=max(get(R),pos[i]+w[i]);
        t[i][0]=upper_bound(pos+1,pos+n+1,re)-pos;
        if (t[i][0]<=n) c[i][0]=pos[t[i][0]]-re;
        update(i,re);
    }
    //FOR(i,1,n) printf("%d ",t[i][0]);ENDL;
    FOR(i,1,18)
        FOR(j,1,n){
            t[j][i]=t[t[j][i-1]][i-1];
            c[j][i]=c[j][i-1]+c[t[j][i-1]][i-1];
        }
}
int main(){
    //INPUT;
    prepare();
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        int ans=0;
        FORD(i,18,0) if (t[x][i]<=y&&t[x][i]!=0)
            ans+=c[x][i],x=t[x][i];
        printf("%d\n",ans);
    }
}