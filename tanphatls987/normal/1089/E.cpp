#include <bits/stdc++.h>

using namespace std;

int n;
int mark[10];

void print(int a, int b) {
    cout << char('a' + a - 1) << b << ' ';
}

void solve(int n) {
    if (n == 10) {
        for (int i = 1; i <= 8; ++i) print(1, i);
        for (int i = 6; i <= 8; ++i) print(i, 8);
        return;
    }
    int x = 1, y = 1, ncnt = 1;
    print(x, y);
    while (n > 1) {
        --n;
        ++ncnt;
        if (n == 1 && y < 8) {
            y = 8;
        }
        else if (n == 2 && x == 7 && y < 8) {
            y = 8;
        }
        else if (y == 8) {
            for (int i = 1; i < 8; ++i) if (!mark[i]) x = i;
        }
        else if (ncnt > 8) {
            ncnt = 1;
            ++y;
        }
        else {
            x = x % 8 + 1;
        }
        print(x, y);
        if (y == 8) mark[x] = 1;
    }
    print(8, 8);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    solve(n);
    return 0;
}