#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
const int mod=1e9+7;
long long a[maxn],ans=0;
vector<pair<long long,int> > val[maxn];
bool vis[maxn];
int n;
vector<int> e[maxn];

long long gcd(long long u,long long v){
    return v?gcd(v,u%v):u;
}

long long g(long long u,long long v){
    if (u<v) swap(u,v);
    return gcd(u,v);
}

void push(int u,long long k,int t){
    for (auto &c:val[u]){
        if (c.first==k){
            c.second+=t;
            return;
        }
    }
    val[u].push_back({k,t});
}

long long get_sum(int u){
    long long cnt=0;
    for (auto c:val[u]){
        cnt=(cnt+c.first*c.second)%mod;
    }
    return cnt;
}

void dfs(int u){
    vis[u]=1;
    push(u,a[u],1);
    ans=(ans+get_sum(u))%mod;
//    cout<<u<<" "<<ans<<endl;
    for (auto c:e[u]){
        if (!vis[c]){
            for (auto k:val[u]){
                push(c,g(k.first,a[c]),k.second);
//                val[c].push_back({g(k.first,a[c]),k.second});
            }
            dfs(c);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}