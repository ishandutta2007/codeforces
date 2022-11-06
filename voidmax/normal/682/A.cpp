#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

typedef long long base;

base n, m;
base arr[5][2];

void Do(int n, int i) {
    if (n == 0) return;
    if (n % 5 == 0) {
        For(j, 0, 5) arr[j][i] += n / 5;
        return;
    }
    ++arr[n % 5][i];
    Do(n - 1, i);
}

base cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    Do(n, 0); Do(m, 1);
    For(i, 0, 5) {
        cnt += arr[i][0] * arr[(5 - i) % 5][1];
    }
    cout << cnt << endl;
}