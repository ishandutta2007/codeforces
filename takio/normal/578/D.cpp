#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 100100;
const ULL M = 1LL << 33;
const double eps = 0;

char s[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    scanf ("%s", s);
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            res += n * (m - 1);
        }
    }
    int e = 0;
    for (int i = 0; i < n - 1; i++) {
//        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == s[i + 1]) continue;
            e = max (e, i + 1);
            while (e < n - 1 && s[e + 1] == s[e - 1]) e++;
            res -= max (0, e - i);
//            cout << i <<' ' << e << endl;
//        }
    }
    cout << res << endl;
}