#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 2e5+5;
ht adj[MX];
bool in[MX];
void solve(){ 
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        adj[i].clear();
        in[i] = true;
    }
    for(int i=0;i<m;i++) {
        int u, v; scanf("%d%d",&u,&v);
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    queue<int> q; 
    for(int i=0;i<n;i++) {
        if(adj[i].size()<k-1) {
            q.push(i);
            in[i] = false;
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int next : adj[x]) {
            adj[next].erase(x);
            if(in[next]) {
                if(adj[next].size()<k-1) {
                    in[next] = false;
                    q.push(next);
                }
            }
        }
    }
    queue<int> v;
    for(int i=0;i<n;i++) {
        if(in[i] && adj[i].size()==k-1) {
            v.push(i);
        }
    }
    while(!v.empty()) {
        int x = v.front();
        v.pop();
        bool work = in[x];
        if(!work) {
            for(int next : adj[x]) {
                adj[next].erase(x);
                if(in[next]) {
                    if(adj[next].size()<k-1) in[next] = false;
                    if(adj[next].size()==k-1) v.push(next);
                }
            }
            continue;
        }
        ht clique;
        for(int next : adj[x]) {
            if(!in[next]) {
                work = false;
                break;
            }
            clique.insert(next);
        }
        clique.insert(x);
        if(!work) {
            in[x] = false;
            for(int next : adj[x]) {
                adj[next].erase(x);
                if(in[next]) {
                    if(adj[next].size()<k-1) in[next] = false;
                    if(adj[next].size()==k-1) v.push(next);
                }
            }
            continue;
        }
        if(k<=500) {
            vector<int> v;
            for(int curr : clique)
                v.push_back(curr);
            for(int i=0;i<v.size();i++) {
                int cnt = 0;
                for(int j=0;j<v.size();j++) {
                    if(adj[v[i]].find(v[j])!=adj[v[i]].end()) ++cnt;
                }
                if(cnt<k-1) {
                    work = false;
                    break;
                }
            }
        }
        else {
            for(int curr : clique) {
                int cnt = 0;
                for(int next : adj[curr]) {
                    if(clique.find(next)!=clique.end()) ++cnt;
                }
                if(cnt<k-1) {
                    work=  false;
                    break;
                }
            }
        }
        if(!work) {
            in[x] = false;
            for(int next : adj[x]) {
                adj[next].erase(x);
                if(in[next]) {
                    if(adj[next].size()<k-1) in[next] = false;
                    if(adj[next].size()==k-1) v.push(next);
                }
            }
            continue;
        }
        printf("%d\n",2);
        for(int curr : clique) printf("%d ", curr+1);
        printf("\n");
        return;
    }
    //might have to optimize finding cliques...?
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(in[i] && adj[i].size()>=k) ans.push_back(i);
    }
    if(ans.size()==0) printf("%d\n",-1);
    else {
        printf("%d %d\n", 1, ans.size());
        for(int curr : ans) printf("%d ", curr+1);
        printf("\n");
    }
}
int main() {
    int t; scanf("%d",&t);
    while(t--) {
        solve();
    }
}