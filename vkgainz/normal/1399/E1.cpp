#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pi;
int n;
ll subtreesz[100001];
int priority[100001];
ll s;
vector<pi> adj[100001];
ll totSum;

struct cmp{
    bool operator() (const pi &a, const pi &b) const{
        ll x = (ll) (a.first-a.first/2)*a.second;
        ll y = (ll) (b.first-b.first/2)*b.second;
        return x>y;
    }
};
multiset<pi,cmp> in;
void dfs(int c,int p){
    if(c==0 || adj[c].size()>=2){
        subtreesz[c] = 0;
    }
    else{
        subtreesz[c] = 1;
    }
    for(pi n : adj[c]){
        if(n.first!=p){
            priority[n.first] = priority[c]+1;
            dfs(n.first,c);
            subtreesz[c]+=subtreesz[n.first];
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%llu",&n,&s);
        in.clear();
        for(int i=0;i<n;i++) subtreesz[i] = 0;
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<n;i++) priority[i] = 0;
        for(int i=0;i<n-1;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            a--; b--;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        dfs(0,-1);
        totSum =0;
        for(int i=0;i<n;i++){
            for(pi j : adj[i]){
                if(priority[i]>priority[j.first]){
                    totSum+=(ll) subtreesz[i]*j.second;
                    in.insert(make_pair(j.second,subtreesz[i]));
                }
            }
        }
        int numStep = 0;
        while(totSum>s){
            numStep++;
            auto it = in.begin();
            int w = (*it).first;
            int neww = (*it).first/2;
            int freq = (*it).second;
            totSum-=(ll) (w-neww)*(freq);
            if(neww!=0){
                in.insert(make_pair(neww,freq));
            }
            in.erase(in.lower_bound(make_pair(w,freq)));

        }
        cout << numStep << endl;

    }
}