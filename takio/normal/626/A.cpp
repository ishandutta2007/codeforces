#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 1010;

char s[N];

int main() {
//    freopen ("in.txt", "r", stdin);
    int n, res = 0;
    cin >> n;
    scanf ("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = 0, y = 0;
            for (int k = i; k <= j; k++) {
                if (s[k] == 'U') x++;
                if (s[k] == 'D') x--;
                if (s[k] == 'L') y++;
                if (s[k] == 'R') y--;
            }
            if (x == 0 && y == 0) res++;
        }
    }
    cout << res << endl;
    return 0;
}