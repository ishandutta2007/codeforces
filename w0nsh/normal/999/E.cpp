#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <stack>

int n, m, s;
std::vector<std::vector<int> > g_orig;
// scc
std::vector<std::vector<int> > g_rev;
std::vector<std::vector<int> > g;
int scc_num;
std::vector<std::vector<int> > nodes_in;
std::vector<int> which_scc;

std::vector<bool> visited;
std::stack<int> stack;

// answer
std::vector<bool> good;

void answer(){
    good.resize(scc_num);
    for(int i = 0; i < scc_num; ++i){
        for(auto ch : g[i]){
            good[ch] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < scc_num; ++i){
        if(!good[i] && which_scc[s] != i) count++;
    }
    std::printf("%d\n", count);
}

void dfs_scc_first(int v){
    visited[v] = true;
    for(auto ch : g_orig[v]){
        if(visited[ch]) continue;
        dfs_scc_first(ch);
    }
    stack.push(v);
}

void dfs_scc_second(int v){
    visited[v] = true;
    which_scc[v] = scc_num;
    nodes_in[scc_num].push_back(v);
    for(auto ch : g_rev[v]){
        if(visited[ch]){
            if(which_scc[ch] != scc_num)
                g[which_scc[ch]].push_back(scc_num);
        }else{
            dfs_scc_second(ch);
        }
    }
}

void calc_scc(){
    visited = std::vector<bool>(n, false);
    for(int i = 0; i < n; ++i){
        if(visited[i]) continue;
        dfs_scc_first(i);
    }
    which_scc.resize(n);
    std::fill(visited.begin(), visited.end(), false);
    while(!stack.empty()){
        int cur = stack.top();
        stack.pop();
        if(visited[cur]) continue;
        g.emplace_back();
        nodes_in.emplace_back();
        dfs_scc_second(cur);
        scc_num++;
    }
}


void read(){
    std::scanf("%d%d%d", &n, &m, &s);
    --s;
    g_orig.resize(n);
    g_rev.resize(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        std::scanf("%d%d", &a, &b);
        a--;b--;
        g_orig[a].push_back(b);
        g_rev[b].push_back(a);
    }
}

int main(){
    read();
    calc_scc();
    answer();
    return 0;
}