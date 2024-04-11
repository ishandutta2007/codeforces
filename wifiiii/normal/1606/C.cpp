#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pw[19];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pw[0] = 1;
    for(int i = 1; i <= 18; ++i) pw[i] = pw[i-1] * 10;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ans;
        for(int i = 1; i < n; ++i) {
            int tmp = pw[a[i] - a[i-1]];
            if(k >= tmp - 1) {
                k -= tmp - 1;
                ans.push_back(tmp - 1);
            } else {
                ans.push_back(k + 1);
                k = -1;
                break;
            }
        }
        if(k != -1) ans.push_back(k + 1);
        reverse(ans.begin(), ans.end());
        for(int i : ans) cout << i;
        cout << endl;
    }
}