#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main () {
    int n, cnt = 0, p, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p >> q;
        if (p + 2 <= q) cnt++;
    }
    cout << cnt << endl;
}