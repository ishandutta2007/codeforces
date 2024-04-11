#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n % 2 == 1 && a[0] % 2 == 1 && a[n - 1] % 2 == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;    
}