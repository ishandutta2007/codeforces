#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    long long d = n / k;
    if (d & 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}