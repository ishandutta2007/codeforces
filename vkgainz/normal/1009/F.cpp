#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
vector<int> adj[1000001];
struct cmp {
    bool operator() (const pair<int,int> &x, const pair<int,int> &y) const{
        if(x.s!=y.s) return x.s>y.s;
        return x.f<y.f;
    }
};
multiset<pair<int, int>, cmp> in[1000001];
map<int ,int> freq[1000001];
int depth[1000001];
int ans[1000001];
void dfs(int curr, int par) {
    in[curr].insert({depth[curr],1});
    ++freq[curr][depth[curr]];
    for(int next : adj[curr]) if(next!=par) {
        depth[next] = depth[curr]+1;
        dfs(next,curr);
        if(in[next].size()>in[curr].size()) {
            swap(in[next], in[curr]);
            swap(freq[next], freq[curr]);
        }
        //check insertion
        for(auto &it : freq[next]) {
            int d = it.f;
            int f = it.s;
            if(in[curr].find({d,freq[curr][d]})!=in[curr].end())
                in[curr].erase({d,freq[curr][d]});
            freq[curr][d]+=f;
            in[curr].insert({d,freq[curr][d]});
        }
        in[next].clear();
        freq[next].clear();
    }
    auto it = in[curr].begin();
    ans[curr] = (*it).f-depth[curr];
}
int main() {
    int n; scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        int x,y; scanf("%d%d",&x,&y);
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++) printf("%d\n",ans[i]);
}