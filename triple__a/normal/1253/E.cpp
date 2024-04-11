#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=107;
const int maxm=200007;
int n,m,a[maxn],b[maxn],p[maxn],dp[maxm][maxn];

bool cmp(int u,int v){
    return a[u]<a[v];
}
int main(){
    scanf("%d%d",&n,&m);
    rep1(i,n){
        scanf("%d%d",&a[i],&b[i]);
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    dp[0][0]=0;
    rep1(i,m){
        dp[i][0]=m;
    }
    rep1(i,n){
        int j=p[i];
        dp[0][i]=0;
        for (int k=1;k<=min(a[j]+b[j],m);++k){
            dp[k][i]=min(dp[max(0,min(k,a[j]-b[j]-1))][i-1],max(0,a[j]-b[j]-1));
        }
        for (int k=a[j]+b[j]+1;k<=m;++k){
            int r=k-a[j]-b[j];
            dp[k][i]=min(min(dp[k][i-1],dp[max(0,a[j]-b[j]-1-r)][i-1]+r),max(a[j]-b[j]-1,r));
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}