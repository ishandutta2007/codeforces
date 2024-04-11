#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define LL long long
using namespace std;

int main () {
    int n;
    cin >> n;
    if (n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while (n - 4 >= 4) {
        printf ("%d - %d = 1\n", n , n - 1);
        printf ("%d - %d = 1\n", n - 2 , n - 3);
        printf ("1 - 1 = 0\n");
        printf ("%d + 0 = %d\n", n - 4, n - 4);
        n -= 4;
    }
    if (n == 7) {
        printf ("7 - 6 = 1\n");
        printf ("5 * 1 = 5\n");
        printf ("5 * 4 = 20\n");
        printf ("20 + 3 = 23\n");
        printf ("2 - 1 = 1\n");
        printf ("23 + 1 = 24\n");
    } else if (n == 6) {
        printf ("6 - 5 = 1\n");
        printf ("1 * 4 = 4\n");
        printf ("4 * 3 = 12\n");
        printf ("12 * 2 = 24\n");
        printf ("24 * 1 = 24\n");
    } else if (n == 5) {
        printf ("5 * 4 = 20\n");
        printf ("20 + 3 = 23\n");
        printf ("2 - 1 = 1\n");
        printf ("23 + 1 = 24\n");
    } else {
        printf ("4 * 3 = 12\n");
        printf ("12 * 2 = 24\n");
        printf ("24 * 1 = 24\n");
    }
}