#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 2e5+5;
vector<int> adj[MX];
int d[MX];
struct cmp {
    bool operator() (const int &x, const int &y) {
        if(d[x]!=d[y])
            return d[x]>d[y];
        return x<y;
    }
};
int dfs(int curr, int par, int k) {
    int ret = -1;
    set<int, cmp> in;
    bool leaf = true;
    for(int next : adj[curr]) if(next!=par) {
        int x = dfs(next, curr, k);
        leaf = false;
        if(x==-1)
            return -1;
        in.insert(x);
    }
    if(leaf) {
        return curr;
    }
    auto it = in.begin();
    if(in.size()==1) {
        ret = (*it);
    }
    else {
        if(d[(*it)]-d[curr]+1<=k) {
            ret = *in.rbegin();
        }
        else {
            int x = (*it);
            ++it;
            if(it==in.end() || d[(*it)]-d[curr]+1<=k) {
                ret = x;
            }
        }
    }
    if(curr==0) {
        if(ret==-1) return -1;
        if(d[ret]>k) return -1;
        else return ret;
    }
    else {
        return ret;
    }
}
void init(int curr, int par) {
    for(int next : adj[curr]) if(next !=par) {
        d[next] = d[curr]+1;
        init(next, curr);
    }
}
void solve() {
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        adj[i].clear();
        d[i] = 0;
    }
    for(int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(0, -1);
    int lo = 1, hi = n;
    //[lo, hi]
    for(int i=0;i<20;i++) {
        int mid = (lo+hi)/2;
        if(dfs(0, -1, mid)!=-1) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    cout << lo << "\n";
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}