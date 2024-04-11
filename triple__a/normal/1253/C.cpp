#include<bits/stdc++.h>
#define int long long
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
const int maxn=200007;
int n,k,a[maxn],ans[maxn],md[maxn],ret=0;

#undef int
int main(){
    scanf("%lld%lld",&n,&k);
    rep1(i,n) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    rep1(i,n){
        md[i%k]+=a[i];
        ans[i]+=md[i%k];
    }
    rep1(i,n){
        ans[i]+=ans[i-1];
    }
    rep1(i,n){
        printf("%lld ",ans[i]);
    }
    return 0;
}