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
        vector<int> a(2 * n);
        for(int i = 0; i < 2 * n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int i = 0, j = 2 * n - 1;
        vector<int> ans;
        while(i <= j) {
            ans.push_back(a[i++]);
            if(i <= j) ans.push_back(a[j--]);
        }
        for(int i : ans) cout << i << " ";
        cout << '\n';
    }
}