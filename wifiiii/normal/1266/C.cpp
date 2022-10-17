#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if(m == 1) {
        for(int i = 2; i <= n + 1; ++i) {
            cout << i << "\n";
        }
    } else {
        for(int i = 1; i <= n; ++i) {
            for(int j = n + 1; j <= n + m; ++j) {
                cout << i * j << " ";
            }
            cout << endl;
        }
    }
}