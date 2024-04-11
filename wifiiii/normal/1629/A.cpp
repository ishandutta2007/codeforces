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
        vector<int> a(n), b(n), ord(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        for(int i = 0; i < n; ++i) ord[i] = i;
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
        for(int i : ord) {
            if(k >= a[i]) {
                k += b[i];
            } else {
                break;
            }
        }
        cout << k << '\n';
    }
}