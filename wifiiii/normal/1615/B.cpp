#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int a[20][N];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < 20; ++i) {
        for(int j = 1; j < N; ++j) {
            a[i][j] = a[i][j - 1] + (j >> i & 1);
        }
    }
    while(t--) {
        int l, r;
        cin >> l >> r;
        int mx = 0;
        for(int i = 0; i < 20; ++i) {
            mx = max(mx, a[i][r] - a[i][l - 1]);
        }
        cout << r - l + 1 - mx << '\n';
    }
}