#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
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
const int N=20;

int c[N][N],n,m,f[1<<N];
string s[N];
vector <int> h[30],e;
int main(){
    cin>>n>>m;
    REP(i,0,n) cin>>s[i];
    REP(i,0,n)
        REP(j,0,m) cin>>c[i][j];
    REP(i,1,1<<n) f[i]=inf;
    REP(j,0,m){
        FOR(i,0,25) h[i].clear();
        REP(i,0,n) h[s[i][j]-'a'].push_back(i);
        FOR(i,0,25) if (!h[i].empty()){
            int m1=h[i].size(),cost=0,dec=0,idx=0;
            REP(k,0,m1) {
                cost+=c[h[i][k]][j],dec=max(dec,c[h[i][k]][j]);
                idx+=1<<h[i][k];
            }
            //printf("%d %d %d %d %d\n",j,i,cost,dec,idx);
            f[idx]=min(f[idx],cost-dec);
        }
    }

    REP(i,0,n) f[1<<i]=min(f[1<<i],*min_element(c[i],c[i]+m));
    //REP(i,1,1<<n) cout<<f[i]<<" ";ENDL;
    REP(i,0,1<<n) if (f[i]!=inf){
        int cost=0;
        for(int j=0;(1<<j)<=i;j++) if (i&(1<<j)) cost+=f[1<<j];
        if (cost>=f[i]) e.push_back(i);
    }
    REP(i,0,1<<n)
        for(auto j:e) f[i|j]=min(f[i|j],f[i]+f[j]);
    cout<<f[(1<<n)-1];
}