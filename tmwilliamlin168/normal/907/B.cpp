#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <iomanip>
#include <set>
#include <sstream>
#include <ctime>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))

#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;

using namespace std;

char c[15][15][15];

void can(bool flag) {
    if (flag == 0) for (int t = 1; t <= 9; ++t) for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) if (c[t][i][j] == '.') c[t][i][j] = '!';
    int p1 = 1, p2 = 3;
    for (int i = 1; i <= 3; ++i) {
        for (int t = p1; t <= p2; ++t) {
            for (int j = 1; j <= 3; ++j) {
                if ((t % 3) != 1 && j == 1) cout << " ";
                cout << c[t][i][j];
            }
        }
        cout << endl;
        if (p2 != 9 && i == 3) cout << endl;
        if (i == 3 && p2 != 9)p1 += 3, p2 += 3, i = 0;
    }
}

int true_pos(int x, int y) {
    return ((x - 1) / 3 * 3 + (y - 1) / 3 + 1);
}

int main()
{
    fast_io;
    int x, y, p1, x1, y1;

    for (int t = 1; t <= 9; ++t) {
        for (int i = 1; i <= 9; ++i) {
            char x;
            cin >> x;
            c[true_pos(t, i)][(t - 1) % 3 + 1][(i - 1) % 3 + 1] = x;
        }
    }
    cin >> x >> y;
    p1 = (x - 1) / 3 + 1;
    x1 = (x - 1) % 3 + 1;
    y1 = (y - 1) % 3 + 1;
    int now = 1;
    bool flag = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
        if (i == x1 && j == y1) {flag = 1; break;}
        now++;
    }
    if (flag) break;
    }
    p1 = now;

    flag = 0;

    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) if (c[p1][i][j] == '.') {flag = 1; c[p1][i][j] = '!';}

    can(flag);
    return 0;
}