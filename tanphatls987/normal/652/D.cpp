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
const int N=5e5+10;

int n,a[N],h[N],mark[N],ans[N],p[N],b[N];
int s[N];
void prepare(){
    scanf("%d",&n);
    REP(i,0,n<<1) scanf("%d",a+i);
    REP(i,0,n<<1) p[i]=a[i];
    sort(p,p+2*n);
    REP(i,0,n<<1) h[lower_bound(p,p+2*n,a[i])-p+1]=i/2;
}
void add(int x,int v){
    while (x){
        b[x]+=v;
        x-=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x<=2*n){
        ans+=b[x];
        x+=x&-x;
    }
    return ans;
}
void solve(){
    FOR(i,1,2*n){
        if (!mark[h[i]]){
            mark[h[i]]=i;
            continue;
        }
        ans[h[i]]=get(mark[h[i]]);
        add(mark[h[i]],1);
    }
    REP(i,0,n) printf("%d\n",ans[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}