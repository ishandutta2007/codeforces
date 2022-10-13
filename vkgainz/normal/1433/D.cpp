#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int par[5005];
int sz[5005];
vector<pair<int,int>> ans;
struct dsu {
    void init(int n) {
        for(int i=0;i<n;i++) {
            par[i] = i, sz[i] = 1;
        }
    }
    int find(int x) {
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int a,int b) {
        int x = find(a), y = find(b);
        if(x!=y) {
            if(sz[x]<sz[y]) swap(x,y);
            sz[x]+=sz[y];
            par[y] = x;
        }
    }
};
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        ans.clear();
        dsu d;
        d.init(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(a[i]!=a[j]) {
                    if(d.find(i)!=d.find(j)) {
                        d.merge(i,j);
                        ans.push_back({i,j});
                    }
                }

            }
        }
        if(ans.size()==n-1) {
            cout << "YES" << endl;
            for(auto &it : ans) {
                cout << it.f+1 << " " << it.s+1 << endl;
            }
        }
        else cout << "NO" << endl;
       
    }
}