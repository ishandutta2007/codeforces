#include <bits/stdc++.h>
using namespace std;

int query(int y) {
    cout << y << "\n";
    int r; cin >> r;
    return r;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> q;
        q.push_back(0);
        for(int i = 1; i < n; i++)
            q.push_back(i ^ (i - 1));
        int ans = n - 1;
        for(auto &it : q) {
            if(query(it) == 1) {
                ans = it;
                break;
            }
        }

    }
}