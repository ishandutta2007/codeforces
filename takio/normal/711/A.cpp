#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 200100;

char s[N][10];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, flag = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", s[i]);
//        cout << s[i] << endl;
        if (s[i][0] == 'O' && s[i][1] == 'O' && flag) s[i][0] = s[i][1] = '+', flag = 0;
        if (s[i][3] == 'O' && s[i][4] == 'O' && flag) s[i][3] = s[i][4] = '+', flag = 0;
    }
    if (flag) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) printf ("%s\n", s[i]);
    }
}