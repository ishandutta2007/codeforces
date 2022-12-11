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
const int N=1e5+10;

int n,m,MOD,q[N],h[N];
vector <int> v[N];
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}

int BFS(int st){
    int top=1,bot=1;
    q[1]=st;
    h[st]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (!h[y]){
            h[y]=1;
            q[++bot]=y;
        }
    }
    return bot;
}
ll solve(){
    ll ans=1;
    int k=0;
    FOR(i,1,n) if (!h[i]) {
        ans=ans*BFS(i)%MOD;
        k++;
    }
    if (k>1) return ans*power(n,k-2)%MOD;
    return 1%MOD;
}
int main(){
    scanf("%d%d%d",&n,&m,&MOD);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<solve();
}