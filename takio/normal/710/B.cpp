#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 300100;

int a[N];

int main()
{
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + 1 + n);
    int mid = a[(n + 1) / 2];
    cout << mid << endl;
//    LL res = 0;
//    for (int i = 1; i <= n; i++) {
//        res += abs (a[i] - mid);
//    }
//    cout << res << endl;
    return 0;
}