#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u]++, a[v]++;
    }
    for(int i = 1; i <= n; i++) if (a[i] == 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}