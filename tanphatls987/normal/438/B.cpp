#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=1e5+10;

typedef long long ll;

int h[N]={0},v[N],t[N],r[N],n,m,x,y;
vector <int> a[N];
bool comp(int x,int y){
    return v[x]>v[y];
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&v[i]);
    FOR(i,1,m) scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
    FOR(i,1,n) r[i]=i;
    sort(r+1,r+n+1,comp);
}
int root(int x){
    while (t[x]>0) x=t[x];
    return x;
}
void mergetree(int x,int y){
    if (t[x]<t[y]) t[x]+=t[y],t[y]=x;
    else t[y]+=t[x],t[x]=y;
}
void solve(){
    ll ans=0;
    memset(t,-1,sizeof(t));
    FOR(i,1,n){
        int cur=r[i];
        REP(j,0,a[cur].size()) if (h[a[cur][j]]){
            int x=root(cur),y=root(a[cur][j]);
            if (x!=y){
                ans+=1LL*t[x]*t[y]*v[cur];
                mergetree(x,y);
            }
        }
        h[cur]=1;
    }
    cout<<(0.+2*ans)/(1LL*n*(n-1));
}
int main(){
    prepare();
    solve();
}