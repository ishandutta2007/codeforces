#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if(n >= 30) {
        cout << m << "\n";
        return 0;
    }
    cout << (m) % (1 << n) << "\n";
}