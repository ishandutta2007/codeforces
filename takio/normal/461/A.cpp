#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 300010;
int a[N];

int main () {
    int n;
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    sort (a + 1, a + 1 + n);
    LL res = 0;
    res += sum;
    for (int i = 1; i < n; i++) {
        res += sum;
        sum -= a[i];
    }
    cout << res << endl;
}