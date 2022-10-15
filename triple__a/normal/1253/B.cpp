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
int n;
vector<int> ans;
set<int> s,s0;

int main(){
    scanf("%d",&n);
    int u;
    int l=-1;
    rep(i,n){
        scanf("%d",&u);
        if (u>0){
            if (s0.find(u)!=s0.end()){
                printf("-1");
                return 0;
            }
            s.insert(u);
            s0.insert(u);
        }
        else{
            if (s.find(-u)==s.end()){
                printf("-1");
                return 0;
            }
            s.erase(-u);
            if (!s.size()){
                ans.push_back(i-l);
                l=i;
                s0.clear();
            }
        }
    }
    if (s0.size()){
        printf("-1");
        return 0;
    }
    printf("%d\n",ans.size());
    for (auto c:ans){
        printf("%d ",c);
    }
    return 0;
}