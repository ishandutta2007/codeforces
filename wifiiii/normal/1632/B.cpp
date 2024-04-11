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
        int h = 1 << (31 - __builtin_clz(n - 1));
        for(int i = n - 1; i >= h; --i) cout << i << ' ';
        for(int i = 0; i < h; ++i) cout << i << ' ';
        cout << '\n';
    }
}