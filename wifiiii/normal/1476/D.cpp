#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 600005;
int par[maxn], sz[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x == y) return;
    sz[y]+=sz[x];
    par[x]=y;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> g(2 * (n + 1));
        for(int i = 0; i < 2 * (n + 1); ++i) par[i] = i, sz[i] = 1;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'L') {
                merge(i+1, i+n+1);
            } else {
                merge(i, i+1+n+1);
            }
        }
        for(int i = 0; i < n+1; ++i) {
            cout << sz[find(i)] << " ";
        }
        cout << endl;
    }
}