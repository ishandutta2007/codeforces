#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int prime[maxn],np[maxn],mp[maxn],tot=0;
void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i, mp[i] = i;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           mp[i*prime[j]] = prime[j];
           if(i%prime[j]==0) break;
       }
   }
}
vector<int> fac(int x) {
    assert(x < maxn && x > 1);
    vector<int> ret;
    while(x > 1) {
        ret.push_back(mp[x]);
        x /= mp[x];
    }
    return ret;
}
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
set<int> g[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(maxn - 1);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 1; i < maxn; ++i) par[i] = i;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        vector<int> d = fac(a[i]);
        for(int j : d) par[find(j)] = find(a[i]);
    }
    for(int i = 0; i < n; ++i) {
        vector<int> d = fac(a[i] + 1);
        for(int j : d) {
            g[find(a[i])].insert(find(j));
            g[find(j)].insert(find(a[i]));
        }
        for(int j : d) {
            for(int k : d) {
                g[find(j)].insert(find(k));
                g[find(k)].insert(find(j));
            }
        }
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int x = find(a[u]), y = find(a[v]);
        if(x == y) {
            cout << 0 << '\n';
        } else {
            if(g[x].count(y)) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}