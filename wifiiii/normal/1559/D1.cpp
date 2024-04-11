#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100005;
int par1[maxn], par2[maxn];
int find1(int x) {return x==par1[x]?x:par1[x]=find1(par1[x]);}
int find2(int x) {return x==par2[x]?x:par2[x]=find2(par2[x]);}
vector<int> g1[maxn], g2[maxn];
void merge1(int u, int v) {
    int x = find1(u), y = find1(v);
    assert(x != y);
    if(g1[x].size() < g1[y].size()) swap(x, y);
    for(int p : g1[y]) g1[x].push_back(p);
    par1[y] = x;
}
void merge2(int u, int v) {
    int x = find2(u), y = find2(v);
    assert(x != y);
    if(g2[x].size() < g2[y].size()) swap(x, y);
    for(int p : g2[y]) g2[x].push_back(p);
    par2[y] = x;
}
typedef pair<int,int> pii;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int m1, m2;
    cin >> m1 >> m2;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i = 0; i < n; ++i) {
        par1[i] = par2[i] = i;
        g1[i].push_back(i);
        g2[i].push_back(i);
    }
    for(int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        merge1(u, v);
    }
    for(int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        merge2(u, v);
    }
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; ++i) {
        if(find1(i) != find1(0) && find2(i) != find2(0)) {
            ans.push_back({0, i});
            merge1(0, i);
            merge2(0, i);
        }
    }
    int i = 0, j = 0;
    while(i < n && j < n) {
        while(i < n && find1(i) == find1(0)) ++i;
        while(j < n && find2(j) == find2(0)) ++j;
        if(i == n || j == n) break;
        ans.push_back({i, j});
        merge1(i, j);
        merge2(i, j);
    }
    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}