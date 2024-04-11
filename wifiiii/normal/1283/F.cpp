#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n - 1; ++i) cin >> a[i];
    vector<int> vis(n+1);
    int rt = a[0];
    vis[a[0]] = 1;
    int mx = n;
    while(vis[mx]) --mx;
    vector<pair<int,int>> ans;
    for(int i = 0; i < n - 1; ++i) {
        if(i+1==n-1 || vis[a[i+1]]) {
            ans.push_back({a[i], mx});
            vis[mx] = 1;
        } else {
            ans.push_back({a[i], a[i+1]});
            vis[a[i+1]] = 1;
        }
        while(vis[mx]) --mx;
    }
    cout << rt << endl;
    for(auto p : ans) cout << p.first << " " << p.second << endl;
}