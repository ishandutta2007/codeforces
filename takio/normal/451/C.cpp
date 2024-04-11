#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main () {
    long long a[5];
    int T;
    cin >> T;
    while (T--)
    {
        long long n, d1, d2, k, t;
        scanf ("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
        if (n % 3 != 0) {printf("no\n"); continue;}
        t = n / 3;
        if ((k - d1 + d2) % 3 == 0){
            a[2] = (k - d1 + d2) / 3;
            a[1] = d1 + a[2];
            a[3] = -d2 + a[2];
            if (!(a[1] < 0 || a[2] < 0 || a[3] < 0 || a[1] > k || a[2] > k || a[3] > k)){
            sort(a + 1, a + 4);
//            for (int i = 1; i <= 3; i++)
//                cout << a[i] << ' '; cout << endl;
            if (a[3] <= t && a[2] <= t && a[1] <= t) {printf ("yes\n"); continue;}
            }
        }
        if ((k + d1 + d2) % 3 == 0){
            a[2] = (k + d1 + d2) / 3;
            a[1] = -d1 + a[2];
            a[3] = -d2 + a[2];
            if (!(a[1] < 0 || a[2] < 0 || a[3] < 0 || a[1] > k || a[2] > k || a[3] > k)){
            sort(a + 1, a + 4);
//            for (int i = 1; i <= 3; i++)
//                cout << a[i] << ' '; cout << endl;
            if (a[3] <= t && a[2] <= t && a[1] <= t) {printf ("yes\n"); continue;}
            }
        }
        if ((k - d1 - d2) % 3 == 0){
            a[2] = (k - d1 - d2) / 3;
            a[1] = d1 + a[2];
            a[3] = d2 + a[2];
            if (!(a[1] < 0 || a[2] < 0 || a[3] < 0 || a[1] > k || a[2] > k || a[3] > k)){
            sort(a + 1, a + 4);
//            for (int i = 1; i <= 3; i++)
//                cout << a[i] << ' '; cout << endl;
            if (a[3] <= t && a[2] <= t && a[1] <= t) {printf ("yes\n"); continue;}
            }
        }
        if ((k + d1 - d2) % 3 == 0){
            a[2] = (k + d1 - d2) / 3;
            a[1] = -d1 + a[2];
            a[3] = d2 + a[2];
            if (!(a[1] < 0 || a[2] < 0 || a[3] < 0 || a[1] > k || a[2] > k || a[3] > k)){
            sort(a + 1, a + 4);
//            for (int i = 1; i <= 3; i++)
//                cout << a[i] << ' '; cout << endl;
            if (a[3] <= t && a[2] <= t && a[1] <= t) {printf ("yes\n"); continue;}
            }
        }
        printf("no\n");
    }
}