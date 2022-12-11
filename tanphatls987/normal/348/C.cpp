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

int n,m,q,k,type[N],g[N][350];
ll st[N],a[N],f[350],add[350];
vector <int> b[N];

void prepare(){
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n) scanf("%I64d",a+i);
    int m1,x,m2=int(sqrt(n));
    k=0;
    FOR(i,1,m){
        scanf("%d",&m1);
        type[i]=(m1>=m2)?++k:0;
        FOR(j,1,m1){
            scanf("%d",&x);
            b[i].push_back(x);
            st[i]+=a[x];
        }
    }
    memset(a,0,sizeof(a));
    FOR(i,1,m) if (type[i]){
        for(auto x:b[i]) a[x]=type[i];
        FOR(j,1,m)
            for(auto x:b[j]) g[j][type[i]]+=(a[x]==type[i]);
    }
    memset(a,0,sizeof(a));
}
void modified(int x,int v){
    if (type[x]) add[type[x]]+=v;
    else for(auto i:b[x]) a[i]+=v;
    FOR(i,1,k) f[i]+=1LL*g[x][i]*v;
}
ll get(int x){
    ll ans=st[x];
    if (type[x]) return ans+f[type[x]];
    for(auto i:b[x]) ans+=a[i];
    FOR(i,1,k) ans+=add[i]*g[x][i];
    return ans;
}
int main(){
    prepare();
    char ch;
    int x,v;
    while (q--){
        scanf("\n%c%d",&ch,&x);
        if (ch=='?') printf("%I64d\n",get(x));
        else {
            scanf("%d",&v);
            modified(x,v);
        }
    }
}