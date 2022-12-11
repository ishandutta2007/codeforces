#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int n,st,w[N],q[N];
ll f[N];
vector <int> v[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",w+i);
    REP(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d",&st);
}
bool comp(int x,int y){
    return f[x]>f[y];
}
void DFS(int par,int x){
    for(auto y:v[x]) if (y!=par) DFS(x,y);
    sort(v[x].begin(),v[x].end(),comp);
    int m1=v[x].size();
    f[x]=(par>0);
    w[x]-=f[x];
    int all=min(w[x],m1);
    REP(i,0,all) if (v[x][i]!=par) {
        f[x]+=f[v[x][i]]+1;
        w[x]--;
    }
    ll sum=0;
    for(auto y:v[x]) if (y!=par) sum+=w[y];
    ll v=min(sum,ll(w[x]));
    f[x]+=v*2;
    w[x]-=v;
}
int main(){
    prepare();
    DFS(0,st);
//    FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
    cout<<f[st];
}