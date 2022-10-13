#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
vector<int> g[180];
int main() {
    int n; cin >> n;
    vector<ll> a;
    for(int i=0;i<n;i++) {
        ll x; cin >> x;
        if(x>0) {
            a.push_back(x);
        }
    }
    if(a.size()>150) {
        cout << 3 << endl;
        return 0;
    }
    for(int i=0;i<a.size();i++) {
        for(int j=i+1;j<a.size();j++) {
            if((a[i]&a[j])>0) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans = 1000000000;
    for(int i=0;i<a.size();i++) {
        vector<int> dist(a.size(), 1000000000);
        vector<int> par(a.size(),-1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int child : g[x]) {
                if(dist[child]==1000000000) {
                    dist[child] = 1+dist[x];
                    par[child] = x;
                    q.push(child);
                }
                else if(par[x]!=child && par[child] !=x) {
                    ans = min(ans,dist[x]+dist[child]+1);
                }
            }
        }
    }
    if(ans==1000000000) cout << -1 << endl;
    else cout << ans << endl;
}