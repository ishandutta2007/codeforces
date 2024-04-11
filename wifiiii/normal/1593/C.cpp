#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll sum = 0;
        for(int i = 0; i < m; ++i) {
            sum += n - a[i];
        }
        for(int i = 0; i < m; ++i) {
            sum -= n - a[i];
            if(a[i] > sum) {
                cout << m - i << '\n';
                break;
            }
        }
    }
}