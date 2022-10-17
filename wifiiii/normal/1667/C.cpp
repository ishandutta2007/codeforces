#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int k = (2 * n + 1) / 3;
    cout << k << '\n';
    for(int i = 1, j = 1; i <= k; ++i) {
        cout << i << " " << j << '\n';
        j += 2; if(j > k) j = 2;
    }
}