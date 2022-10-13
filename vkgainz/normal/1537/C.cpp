#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> h(n);
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        pair<int, int> ans = {0, 1000000000};
        int bst = 1000000000;
        for(int i = 0; i < n - 1; i++) {
            if(h[i + 1] - h[i] < bst) {
                bst = h[i + 1] - h[i];
                ans = {i, i + 1};
            }
        }
        vector<int> left;
        vector<int> ret;
        ret.push_back(h[ans.first]);
        for(int i = 0; i < n; i++) {
            if(i != ans.first && i != ans.second) {
                left.push_back(h[i]);
            }
        }
        for(int i = 0; i < n - 2; i++) {
            if(left[i] >= ret[0])
                ret.push_back(left[i]);
        }
        for(int i = 0; i < n - 2; i++) {
            if(left[i] < ret[0])
                ret.push_back(left[i]);
        }
        ret.push_back(h[ans.second]);
        for(int x : ret) {
            cout << x << " ";
        }
        cout << "\n";
    }
}