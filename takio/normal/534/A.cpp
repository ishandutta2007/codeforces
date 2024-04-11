#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

int main () {
    int n;
    cin >> n;
    if (n <= 2) {
        printf ("1\n1");
        return 0;
    } else if (n == 3) {
        printf ("2\n1 3");
        return 0;
    }
    cout << n << endl;
    for (int i = 2; i <= n; i += 2) {
        printf ("%d ", i);
    }
    for (int i = 1; i <= n; i += 2) {
        printf ("%d ", i);
    }
}