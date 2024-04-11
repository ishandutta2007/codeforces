#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()

vector<vector<int>> gen_edges(int n) {
    vector<vector<int>> ans(n);
    if(n == 1) {
        return ans;
    }
    vector<vector<int>> a = gen_edges(n / 2);
    vector<vector<int>> b = a;
    for(int i = n / 2; i < n; i++) {
        b.push_back(vector<int>());
        for(int j : a[i - n / 2]) {
            b[i].push_back(j + n / 2);
        }
    }
    for(int i = 0; i < n / 2; i++) {
        b[i].push_back(i + n / 2);
        b[i + n / 2].push_back(i);
    }
    return b;
}

vector<int> rotate(vector<int> v, int shift, int n) {
    vector<int> ans(sz(v));
    for(int i = 0; i < sz(v); i++)
        ans[i] = (v[i] ^ shift);
    return ans;
}

vector<int> gen_color(int n) {
    if(n == 1) {
        return {0, 0};
    }
    vector<int> ans(n);
    vector<int> rot;
    vector<bool> power(n);
    power[0] = 1, power[1] = 1;
    for(int i = 2; i < n; i++)
        power[i] = (i % 2 == 0) && power[i / 2];
    for(int i = 1; i < n; i++) {
        if(!power[i])
            rot.push_back(i);
    }
    iota(ans.begin(), ans.end(), 0);
    for(int b = 0; b < sz(rot); b++) {
        vector<int> ins = rotate(ans, rot[b], n);
        ans.insert(ans.end(), ins.begin(), ins.end());
    }
    ans.insert(ans.end(), ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> adj((1 << n));
        for(int i = 0; i < n * (1 << (n - 1)); i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> p(1 << n, -1);
        p[0] = 0;
        vector<bool> left(1 << n, true);
        left[0] = false;
        for(int i = 0; i < n; i++) {
            p[1 << i] = adj[0][i];
            left[p[1 << i]] = false;
        }
        vector<vector<int>> edges = gen_edges(1 << n);
        for(int i = 0; i < (1 << n); i++) {
            if(p[i] >= 0) continue;
            int bef = 0;
            map<int, int> freq; // change to unordered
            for(int x : edges[i]) {
                if(p[x] == -1) continue;
                ++bef;
                for(int y : adj[p[x]]) {
                    if(left[y])
                        ++freq[y];
                }
            }
            for(auto it : freq)
                if(it.second == bef) 
                    p[i] = it.first;
            left[p[i]] = false;
        }
        for(int i = 0; i < (1 << n); i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
        if((1 << n) % n) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> color = gen_color(n);
        vector<int> ans(1 << n);
        for(int i = 0; i < (1 << n); i++) {
            ans[p[i]] = color[i];
        }
        for(int i = 0; i < (1 << n); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}