#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s, v1, v2, t1, t2; cin >> s >> v1 >> v2 >> t1 >> t2;
    long long a = t1 * 2 + v1 * s;
    long long b = t2 * 2 + v2 * s;
    if (a < b) cout << "First" << endl;
    else if (a > b) cout << "Second" << endl;
    else cout << "Friendship" << endl;
    return 0;
}