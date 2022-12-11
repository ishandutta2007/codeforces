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
const int N=5e5+10;

map <int,int> ma;
int t[N],b[N],a[N],ans[N],n,m,x,y;
vector <ii> q[N];
void update(int x,int v){
    while (x){
        b[x]=min(b[x],v);
        x-=x&-x;
    }
}
int get(int x){
    int ans=n+1;
    while (x<=n){
        ans=min(ans,b[x]);
        x+=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        scanf("%d",a+i);
        t[i]=ma[a[i]];
        ma[a[i]]=i;
    }
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        q[y].push_back(ii(x,i));
    }
    FOR(i,0,n) b[i]=n+1;
    FOR(i,1,n){
        update(t[i],i-t[i]);
        for(auto j:q[i]){
            int v=get(j.X);
            ans[j.Y]=v==n+1?-1:v;
        }
    }
    FOR(i,1,m) printf("%d\n",ans[i]);
}