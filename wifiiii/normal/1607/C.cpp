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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(n == 1) {cout << a[0] << endl; continue;}
        sort(a.begin(), a.end());
        int mx = a[0];
        for(int i = 1; i < n; ++i) mx = max(mx, a[i] - a[i-1]);
        cout << mx << '\n';
    }
}