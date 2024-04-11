#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;
int a[N];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        g = __gcd (g, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int t = a[i] / g;
        while (t % 2 == 0) t /= 2;
        while (t % 3 == 0) t /= 3;
        if (t != 1) { cout << "No"; return 0; }
    }
    cout << "Yes";
}