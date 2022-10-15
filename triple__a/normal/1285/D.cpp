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

const int maxn=200007;
int n,u;
vector<int> vec;

int dfs(int dep,vector<int> vec){
    if (dep==-1) return 0;
    vector<int> l,r;
    l.clear(), r.clear();
    for (auto c:vec){
        if (c>>dep&1) r.pb(c);
        else l.pb(c);
    }
    if (l.size()==0) return dfs(dep-1,r);
    if (r.size()==0) return dfs(dep-1,l);
    if (l.size()&&r.size()) return (1<<dep)+min(dfs(dep-1,r),dfs(dep-1,l));
}
int main(){
    scanf("%d",&n);
    rep1(i,n) scanf("%d",&u), vec.pb(u); 
    printf("%d\n",dfs(30,vec));
    return 0;
}