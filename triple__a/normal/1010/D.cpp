#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=1000007;

int n;
string tp[maxn];
vector<int> vec[maxn];
bool crt[maxn],ans[maxn];

bool dfs(int u){
    bool ret=0;
    if (tp[u]=="IN"){
        return crt[u]=vec[u][0];
    }
    if (tp[u]=="NOT"){
        ret=1-dfs(vec[u][0]);
    }
    else{
        bool fg1=dfs(vec[u][0]), fg2=dfs(vec[u][1]);
        if (tp[u]=="AND"){
            ret=fg1&fg2;
        }
        if (tp[u]=="OR"){
            ret=fg1|fg2;
        }
        if (tp[u]=="XOR"){
            ret=fg1^fg2;
        }
    }
    return crt[u]=ret;
}

void dfs2(int u){
    if (tp[u]=="NOT"){
        ans[vec[u][0]]=ans[u];
        dfs2(vec[u][0]);
    }
    if (tp[u]=="AND"){
        if (crt[vec[u][0]]) ans[vec[u][1]]=ans[u];
        if (crt[vec[u][1]]) ans[vec[u][0]]=ans[u];
        dfs2(vec[u][0]), dfs2(vec[u][1]);
    }
    if (tp[u]=="OR"){
        if (!crt[vec[u][1]]) ans[vec[u][0]]=ans[u];
        if (!crt[vec[u][0]]) ans[vec[u][1]]=ans[u];
        dfs2(vec[u][0]), dfs2(vec[u][1]);
    }
    if (tp[u]=="XOR"){
        ans[vec[u][0]]=ans[u];
        ans[vec[u][1]]=ans[u];
        dfs2(vec[u][0]), dfs2(vec[u][1]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>tp[i];
        int u;
        cin>>u;
        vec[i].pb(u);
        if (tp[i]!="IN"&&tp[i]!="NOT"){
            cin>>u;
            vec[i].pb(u);
        }
    }
    ans[1]=1;
    bool ret=dfs(1);
    dfs2(1);
    for (int i=1;i<=n;++i){
        if (tp[i]=="IN"){
            cout<<(ret^ans[i]);
        }
    }
    return 0;
}