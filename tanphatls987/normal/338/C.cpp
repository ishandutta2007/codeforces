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
const int M=1e6,N=8;

vector <int> pri;
vector <ii> e[1<<N];
int t[M],n,g[1<<N][100],f[10000],p3[N+5],add[1<<N],h[N];
ll need[100],a[N];
void prepare(){
    REP(i,2,M) if (!t[i]){
        pri.push_back(i);
        for(int j=i;j<N;j+=i) t[j]=i;
    }
    p3[0]=1;
    FOR(i,1,10) p3[i]=3*p3[i-1];
}
int get(int x,int pos){
    return x/p3[pos]%3;
}
int solve(){
    sort(a,a+n);
    int m=0;
    REP(i,0,n){
        ll tmp=a[i];
        REP(j,0,pri.size()){
            if (1LL*pri[j]*pri[j]>tmp) continue;
            if (tmp%pri[j]==0){
                need[++m]=pri[j];
                while (tmp%pri[j]==0) tmp/=pri[j];
            }
        }
        if (tmp>1) need[++m]=tmp;
    }
    sort(need+1,need+m+1);
//    FOR(i,1,m) cout<<need[i]<<" \n"[i==m];
    m=unique(need+1,need+m+1)-need-1;
//    cout<<m<<'\n';

    REP(i,0,n){
        ll tmp=a[i];
        FOR(j,1,m) while (tmp%need[j]==0) g[1<<i][j]++,tmp/=need[j];
        add[1<<i]=p3[i];
    }
    REP(i,1,1<<n){
        int last=(i&-i);
        FOR(j,1,m) g[i][j]=g[last][j]+g[i^last][j];
        add[i]=add[last]+add[i^last];
    }
    REP(cur,0,n)
        REP(i,0,1<<cur){
            int leaf=0;
            FOR(k,1,m){
                if (g[i][k]>g[1<<cur][k]) leaf=inf;
                else leaf+=g[1<<cur][k]-g[i][k];
            }
            if (leaf<inf){
                if (i!=0||leaf>1) leaf++;
                e[i].push_back(ii(cur,leaf));
//                printf("%d %d %d\n",i,cur,leaf);
            }
        }
    REP(i,1,p3[n]) f[i]=inf;
    int ans=inf;
    REP(i,0,p3[n]){
        int cur=0,c0=0,c1=0;
        int tmp=i;
        REP(j,0,n){
            h[j]=tmp%3;
            tmp/=3;
            if (h[j]==1) cur|=(1<<j);
        }
        FOR(k,0,cur) if ((cur|k)==cur)
            for(auto j:e[k]) if (!h[j.X])
                f[i+add[k]+p3[j.X]]=min(f[i+add[k]+p3[j.X]],f[i]+j.Y);
//                printf("%d %d\n",i+add[k]+p3[j.X],i);
        if (!count(h,h+n,0)) ans=min(ans,f[i]+(count(h,h+n,1)>1));
    }
    return ans;
}
int main(){
//    OUTPUT;
    prepare();
    cin>>n;
    REP(i,0,n) cin>>a[i];
    cout<<solve();
}