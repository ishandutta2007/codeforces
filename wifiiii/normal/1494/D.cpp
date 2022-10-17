#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int a[505][505],ans[55505],par[55505];
int n,tot;
vector<int> g[55505];

int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int solve(vector<int> nodes) {
    if(nodes.size() == 1) return nodes[0];
    int rt = ++tot;
    int m = nodes.size(), mx = 0;
    for(int i=0;i<m;++i) {
        for(int j=i+1;j<m;++j) {
            mx = max(mx, a[nodes[i]][nodes[j]]);
        }
    }
    ans[rt] = mx;
    for(int i=0;i<=m;++i) par[i]=i;
    for(int i=0;i<m;++i) {
        for(int j=i+1;j<m;++j) {
            if(a[nodes[i]][nodes[j]] != mx) {
                par[find(i)]=find(j);
            }
        }
    }
    vector<vector<int>> tmp(m);
    for(int i=0;i<m;++i) tmp[find(i)].push_back(nodes[i]);
    for(int i=0;i<m;++i) {
        if(!tmp[i].empty()) {
            g[rt].push_back(solve(tmp[i]));
        }
    }
    return rt;
}
void print(int rt) {
    for(int v:g[rt]) {
        cout<<v<<" "<<rt<<endl;
        print(v);
    }
}
int main() {
    cin>>n; tot=n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
    for(int i=1;i<=n;++i) ans[i]=a[i][i];
    vector<int> nodes;
    for(int i=1;i<=n;++i) nodes.push_back(i);
    int rt=solve(nodes);
    cout<<tot<<endl;
    for(int i=1;i<=tot;++i) cout<<ans[i]<<" ";cout<<endl;
    cout<<rt<<endl;
    print(rt);
}