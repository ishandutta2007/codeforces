#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int res[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    string s;
    cin >> n >> s >> s;
    if (s[0] == 'w') {
        for (int i = 1, now = 5; i <= 366; i++) {
            res[now]++;
            now++;
            if (now > 7) now = 1;
        }
        cout << res[n] << endl;
        return 0;
    }
    for (int i = 1; i <= 29; i++) res[i] = 12;
    res[30] = 11;
    res[31] = 7;
    cout << res[n] << endl;
}