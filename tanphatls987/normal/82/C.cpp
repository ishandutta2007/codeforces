#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
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
const int N=5e3+10;

int T[N],pri[N],w[N],ans[N],n,p[N],h[N][N]={0};
ii e[N];
vector <int> a[N];
bool comp(int x,int y){
    return pri[x]<pri[y];
}
void DFS(int par,int x){
    T[x]=par;
    for(auto i:a[x]) if (i!=par) DFS(i,e[i].X+e[i].Y-x);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",pri+i);
    FOR(i,1,n-1){
        scanf("%d%d%d",&e[i].X,&e[i].Y,w+i);
        a[e[i].Y].push_back(i);
        a[e[i].X].push_back(i);
    }
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    DFS(0,1);
    //FOR(i,1,n) printf("%d ",T[i]);
    FOR(i,1,n){
        int sel=p[i],x=sel;
        while (x!=1){
            while (h[x][ans[sel]]==w[T[x]]) ans[sel]++;
            h[x][ans[sel]]++;
            ans[sel]++;
            x=e[T[x]].X+e[T[x]].Y-x;
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}