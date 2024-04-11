#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), vis(101);
        vector<int> ans, res;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(!vis[x]) ans.push_back(x);
            else res.push_back(x);
            vis[x] = 1;
        }
        sort(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        for(int i : ans) cout << i << " ";
        for(int i : res) cout << i << " ";
        cout << endl;
    }
}