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
const int N=5e5+10,M=5e5;


int n,q,x,t[N],re[1<<10],c[N]={0},h[N],top=0,a[N];
vector <int> g[N];
ll ans=0;
void del(int x){
    h[x]=0;
    ans-=--top;
    if (a[x]==1) return;
    int m1=g[a[x]].size();
    re[0]=1;
    REP(i,0,m1) re[1<<i]=g[a[x]][i];
    REP(i,1,1<<m1){
        re[i]=re[i&-i]*re[i-(i&-i)];
        c[re[i]]--;
        if (__builtin_popcount(i)%2) ans+=c[re[i]];
        else ans-=c[re[i]];
    }
}
void add(int x){
    h[x]=1;
    ans+=top++;
    //printf("%d %d\n",a[x],ans,);
    if (a[x]==1) return;
    int m1=g[a[x]].size();
    re[0]=1;
    REP(i,0,m1) re[1<<i]=g[a[x]][i];
    REP(i,1,1<<m1){
        re[i]=re[i&-i]*re[i-(i&-i)];
        if (__builtin_popcount(i)%2) ans-=c[re[i]];
        else ans+=c[re[i]];
        c[re[i]]++;
    }
    //printf("%d %d\n",a[x],ans);
}
int main(){
    FOR(i,2,M) if (!t[i])
        for(int j=i;j<=M;j+=i) t[j]=i;
    FOR(i,2,M){
        int x=i;
        while (x>1){
            int tmp=t[x];
            g[i].push_back(tmp);
            while (x%tmp==0) x/=tmp;
        }
    }
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i);
    while (q--){
        scanf("%d",&x);
        if (h[x]) del(x);
        else add(x);
        printf("%lld\n",ans);
    }
}