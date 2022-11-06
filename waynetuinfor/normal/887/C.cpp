#include <bits/stdc++.h>
using namespace std;

int a[25];
int go[6][16] = { {2, 6, 4, 8, 6, 10, 8, 12, 10, 23, 12, 21, 23, 2, 21, 4}, {1, 5, 3, 7, 5, 9, 7, 11, 9, 24, 11, 22, 24, 1, 22, 3},
                  {5, 17, 6, 18, 17, 21, 18, 22, 13, 5, 14, 6, 21, 13, 22, 14}, {7, 19, 8, 20, 19, 23, 20, 24, 15, 7, 16, 8, 23, 15, 24, 16},
                  {9, 19, 10, 17, 19, 4, 17, 3, 4, 14, 3, 16, 14, 9, 16, 10}, {1, 15, 2, 13, 17, 1, 19, 2, 9, 19, 10, 17, 14, 9, 16, 10}};

vector<int> func(vector<int> now, int idx) {
    vector<int> ret(now.begin(), now.end());
    for (int i = 0; i < 16; i += 2) {
        ret[go[idx][i]] = now[go[idx][i + 1]];
    }
    return ret;
}

bool check(vector<int> now) {
    for (int i = 1; i <= 24; i += 4) {
        for (int j = 0; j < 4; ++j) if (now[i + j] != now[i]) return false;
    }
    return true;
}

int main() {
    for (int i = 1; i <= 24; ++i) cin >> a[i];
    for (int i = 0; i < 6; ++i) {
        vector<int> na(a, a + 25);
        if (check(func(na, i))) return cout << "YES" << endl, 0;
        if (check(func(func(func(na, i), i), i))) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
}