#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll sx = 0, sy = 0;
    for(int i = 0; i < 2 * n; ++i) {
        int x, y;
        cin >> x >> y;
        sx += x;
        sy += y;
    }
    sx /= n, sy /= n;
    cout << sx << " " << sy << '\n';
}