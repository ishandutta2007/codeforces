#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 5000010;
int ok[N], a[N];

int main () {
    for (int i = 2; i < N; i++) if (!ok[i]){
        for (int j = i; j < N; j += i) {
            int t = j;
            while (t % i == 0) {
                a[j] ++;
                t /= i;
            }
            ok[j] = 1;
        }
    }
//    for (int i = 1; i <= 6; i++) {
//        cout << i << ' ' << a[i] << endl;
//    }
    for (int i = 1; i < N; i++) {
        a[i] += a[i - 1];
    }
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        printf ("%d\n", a[x] - a[y]);
    }
}