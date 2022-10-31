#include <bits/stdc++.h>
using namespace std;

int n,c[2001],ans[2001];
vector<int> adj[2001];
bool flag = true;

vector<int> dfs(int cur) {
    vector<int> arr;
    for(auto &it:adj[cur]) {
        vector<int> tmp = dfs(it);
        for(auto &it:tmp) arr.push_back(it);
    }
    if(c[cur] > arr.size()) {
        flag = false;
        arr.push_back(cur);
    } else {
        arr.insert(arr.begin() + c[cur], cur);
    }
    return arr;
}

int main() {
    int root = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int p;
        scanf("%d%d",&p,c+i);
        if(p==0) root = i;
        else {
            adj[p].push_back(i);
        }
    }

    vector<int> res = dfs(root);
    if(!flag) {
        puts("NO");
        return 0;
    } else {
        for(int i=0;i<n;i++) ans[res[i]] = i+1;
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }

    return 0;
}