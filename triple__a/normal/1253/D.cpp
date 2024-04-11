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

const int maxn=200007;
int p[maxn]; // rep1(i,n) p[i]=i;
int n,m;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    if (pv<pu) swap(pu,pv);
    p[pu]=pv;
    return pu!=pv;
}

int main(){
    scanf("%d%d",&n,&m);
    rep1(i,n) p[i]=i;
    while (m--){
        int u,v;
        scanf("%d%d",&u,&v);
        unite(u,v);
    }
    set<int> s;
    int ans=0,mx=0;
    rep1(i,n){
        p[i]=find(i);
    }
    rep1(i,n){
        s.insert(p[i]);
        mx=max(mx,p[i]);
//        cout<<mx<<" "<<i<<endl;
        if (mx==i){
            ans+=s.size()-1;
            s.clear();
        }
    }
    printf("%d\n",ans);
    return 0;
}