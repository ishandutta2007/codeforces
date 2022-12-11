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
const int N=1e5+10;

int n,m,x,y,ans[N],range[N][2],b[N<<3],d[N<<3],top=0;
vector <int> v[N],a[N];
void update(int node,int L,int R,int l,int r,int v){
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        d[node]+=v;
        if (!d[node]) b[node]=b[node*2+1]+b[node*2];
        else b[node]=(R-L+1);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,v);
    update(node*2+1,(L+R)/2+1,R,l,r,v);
    if (!d[node]) b[node]=b[2*node]+b[node*2+1];
    else b[node]=R-L+1;
}
void DFS1(int par,int x){
    static int c=0;
    range[x][0]=++c;
    for(auto y:v[x]) if (y!=par) DFS1(x,y);
    range[x][1]=c;
}
void DFS2(int par,int x){
    for(auto i:a[x]){
        update(1,1,n,range[i][0],range[i][1],1);
        update(1,1,n,range[x][0],range[x][1],1);
        top++;
    }
    ans[x]=b[1];
    if (top) ans[x]--;
    for(auto y:v[x]) if (y!=par) DFS2(x,y);
    for(auto i:a[x]){
        update(1,1,n,range[i][0],range[i][1],-1);
        update(1,1,n,range[x][0],range[x][1],-1);
        top--;
    }
}
void solve(){
    DFS1(0,1);
    DFS2(0,1);
//    FOR(i,1,n) printf("%d %d\n",range[i][0],range[i][1]);
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
//    INPUT;
    scanf("%d%d",&n,&m);
    FOR(i,2,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while (m--){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve();
}