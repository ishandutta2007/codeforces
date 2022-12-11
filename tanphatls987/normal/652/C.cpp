#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("mdraft.inp","r",stdin)
#define OUTPUT freopen("mdraft.out","w",stdout)
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
const int N=3e5+10;

int n,f[N],pos[N];
ll prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d",&x);
        pos[x]=i;
    }
    while (m--){
        scanf("%d%d",&x,&y);
        x=pos[x];y=pos[y];
        if (x>y) swap(x,y);
        f[y]=max(f[y],x);
    }
    ll ans=0;
    FOR(i,1,n) {
        f[i]=max(f[i],f[i-1]);
        ans+=i-f[i];
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    cout<<prepare();
}