#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 300020, mod = 1e9 + 7;

char s[N];
int c[4], t[4];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, mx = 0;
    cin >> n >> k;
    scanf ("%s", s);
    for (int i = 0; i < n; i++) {
        mx += max (s[i] - 'a', 'z' - s[i]);
    }
    if (k > mx) return cout << -1, 0;
//    cout << mx << endl;
    for (int i = 0; i < n; i++) {
        mx = max (s[i] - 'a', 'z' - s[i]);
//        cout << mx << endl;
        if (k >= mx) {
            k -= mx;
            if (s[i] - 'a' > 'z' - s[i]) printf ("a");
            else printf ("z");
        } else {
            if (s[i] - k >= 'a') printf ("%c", s[i] - k);
            else printf ("%c", s[i] + k);
            k = 0;
        }
//        cout << ' ';
    }
}