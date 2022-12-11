#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;


struct que{
    int x[2],y[2];
    void read(){
        scanf("%d%d%d%d",x,y,x+1,y+1);
    }
};
int n[2],k,m,b[N<<2],c[N],x,y;
vector <int> a[2][N],p[2][N];
que q[N];
bool ans[N];
void update(int node,int L,int R,int M){
    if (L>M||R<M) return;
    if (L==R){
        b[node]=c[L];
        return;
    }
    update(node*2,L,(L+R)/2,M);
    update(node*2+1,(L+R)/2+1,R,M);
    b[node]=min(b[node*2],b[node*2+1]);
}
int query(int node,int L,int R,int l,int r){
    if (L>r||R<l) return inf;
    if (l<=L&&R<=r) return b[node];
    return min(query(node*2,L,(L+R)/2,l,r),query(node*2+1,(L+R)/2+1,R,l,r));
}
int main(){
    scanf("%d%d%d%d",n,n+1,&k,&m);
    while (k--){
        scanf("%d%d",&x,&y);
        a[0][x].push_back(y);
        a[1][y].push_back(x);
    }
    FOR(i,1,m){
        q[i].read();
        p[0][q[i].x[1]].push_back(i);
        p[1][q[i].y[1]].push_back(i);
    }
    FOR(T,0,1){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        FOR(i,1,n[T]){
            for(auto j:a[T][i]) {
                c[j]=i;
                update(1,1,n[1-T],j);
            }
            //FOR(j,1,n[T]) cout<<c[j]<<" \n"[j==n[T]];
            for(auto j:p[T][i]) {
                //printf("%d %d %d %d %d\n",i,q[j].x[0],q[j].y[0],q[j].x[1],q[j].y[1]);
                if (T) {
                    ans[j]|=(query(1,1,n[1-T],q[j].x[0],q[j].x[1])>=q[j].y[0]);
                   //printf("%d\n",query(1,1,n[1-T],q[j].x[0],q[j].x[1]));
                }
                else {
                    ans[j]|=(query(1,1,n[1-T],q[j].y[0],q[j].y[1])>=q[j].x[0]);
                   //printf("%d\n",query(1,1,n[1-T],q[j].y[0],q[j].y[1]));
                }
            }
        }
    }
    FOR(i,1,m) printf("%s\n",ans[i]?"YES":"NO");
}