#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
const int mod=998244353;

int n,tot,L[N],R[N],ans;
vi s1[N],s2[N];
void dfs(int u){
    L[u]=++tot;
    for(auto v:s2[u]){
        dfs(v);
    }
    R[u]=++tot;
}
set<pii>s;
void dfs2(int u){
    pii d{0,0};
    auto it=s.lower_bound({L[u],R[u]});
    if(it!=s.begin()){
        it--;
        if(it->se>=R[u]){
            d=*it;
            s.erase(it);
        }
    }
    s.insert({L[u],R[u]});
    ans=max(ans,(int)s.size());
    for(auto v:s1[u]){
        dfs2(v);
    }
    if(d.fi){
        s.insert(d);
    }
    s.erase({L[u],R[u]});
}
int solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        s1[a].push_back(i);
    }
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        s2[a].push_back(i);
    }
    dfs(1);
    dfs2(1);
    return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
        ans=tot=0;
        for(int i=1;i<=n;i++){
            s1[i].clear();
            s2[i].clear();
        }
    }
}