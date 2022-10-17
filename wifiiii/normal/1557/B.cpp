#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            if(ord[i] - ord[i-1] != 1) ++cnt;
        }
        cout << (cnt + 1 <= k ? "Yes" : "No") << endl;
    }
}