#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(abs(a - b) > 1 || a + b > n - 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans;
        if(a < b) {
            int i = 1, j = n;
            for(int k = 0; k < b; ++k) {
                ans.push_back(j--);
                ans.push_back(i++);
            }
            while(i <= j) {
                ans.push_back(i++);
            }
        } else if(b < a) {
            int i = 1, j = n;
            for(int k = 0; k < a; ++k) {
                ans.push_back(i++);
                ans.push_back(j--);
            }
            while(i <= j) {
                ans.push_back(j--);
            }
        } else {
            int i = 1, j = n;
            for(int k = 0; k < b; ++k) {
                ans.push_back(j--);
                ans.push_back(i++);
            }
            while(i <= j) {
                ans.push_back(j--);
            }
        }
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}