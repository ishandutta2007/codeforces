#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 27;
int n, m;
long long matr[MAX_N][MAX_N];
map <long long, long long> cnt[MAX_N][MAX_N], cnt2[MAX_N][MAX_N];

bool is_ok(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void gen1(int i, int j, int num, long long pref) {
    //cout << num << ' ' << i << ' ' << j << endl;
    pref = pref ^ matr[i][j];
    if (num == 0) {
        cnt[i][j][pref ^ matr[i][j]]++;
        return;
    }
    if (is_ok(i + 1, j)) gen1(i + 1, j, num - 1, pref);
    if (is_ok(i, j + 1)) gen1(i, j + 1, num - 1, pref);
}

void gen2(int i, int j, int num, long long pref) {
    pref = pref ^ matr[i][j];
    if (num == 0) {
        cnt2[i][j][pref]++;
        return;
    }
    if (is_ok(i - 1, j)) gen2(i - 1, j, num - 1, pref);
    if (is_ok(i, j - 1)) gen2(i, j - 1, num - 1, pref);
}


int main() {
    long long k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
    int tot = n + m - 2;
    gen1(0, 0, tot / 2, 0);
    gen2(n - 1, m - 1, tot - tot / 2, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (pair <long long, long long> elem : cnt[i][j]) {
                //cout << i << ' ' << j << ' ' << elem.first << ' ' << elem.second << endl;
                ans += elem.second * cnt2[i][j][k ^ elem.first];
            }
        }
    }
    cout << ans << endl;
    return 0;
}