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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m;
int f[N],h[N];
ii e[N];
vector <int> v[N];
int DFS(int x){
    if (f[x]!=-1) return f[x];
    f[x]=1;
    for(auto y:v[x]) f[x]=max(f[x],DFS(y)+1);
    return f[x];
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        e[i]=ii(x,y);
        v[x].push_back(y);
    }
    memset(f,-1,sizeof(f));
    FOR(i,1,n) DFS(i);
}
int solve(){
    if (*max_element(f+1,f+n+1)<n) return -1;
    int ans=0;
    FOR(i,1,m){
        ans+=(f[e[i].X]-f[e[i].Y]==1);
        if (ans==n-1) return i;
    }
    return -1;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}