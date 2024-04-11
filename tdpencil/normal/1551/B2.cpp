#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i =0; i < k; ++i) {
            pq.push({0, i});
        }
        vector<int> clrs(n, -1);
        vector<int> a(n);
        vector<vector<int>> cnt(n);
        vector<vector<int>> topb(k);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]-1].push_back(i);
        }
        for(int i = 0; i < n; ++i) {
            vector<pair<int, int>> todo;
            for(int j = 0; j < min(int(cnt[i].size()), k); ++j) {
                pair<int, int> t=pq.top(); 
                pq.pop();
                topb[t.second].push_back(cnt[i][j]);
                t.first++;
                todo.push_back(t);
            }
            for(auto i : todo) {
                pq.push(i);
            }
        }
        int res=1e9;
        for(int i = 0; i < k; ++i) {
            res=min(res, (int)topb[i].size());
        }
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < res; ++j) {
                clrs[topb[i][j]] = i;
            }
        }
       
       for(int i = 0; i < n; ++i) {
           cout << clrs[i] + 1 << " ";
       } 
       cout << endl;
    }
}