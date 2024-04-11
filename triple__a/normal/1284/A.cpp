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

const int maxn=2007;
int n,m,q;
string s[maxn],t[maxn];
int main(){
    cin>>n>>m;
    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];
    cin>>q;
    while (q--){
        int u;
        cin>>u;
        cout<<s[(u-1)%n]<<t[(u-1)%m]<<endl;
    }
    return 0;
}