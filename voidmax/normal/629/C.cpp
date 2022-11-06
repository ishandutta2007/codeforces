
#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second

using namespace std;

typedef long long base;

const base Mod = 1e9 + 7;
int n, k;
string m;
base cnt = 0;
base arr[3004][3004];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    n -= k;
    arr[0][0] = 1;
    For(i, 0, n + 10) {
        For(j, 0, n + 10) {
            arr[i + 1][j + 1] += arr[i][j];
            if (arr[i + 1][j + 1] > Mod) {
                arr[i + 1][j + 1] -= Mod;
            }
        }
        For(j, 1, n + 10) {
            arr[i + 1][j - 1] += arr[i][j];
            if (arr[i + 1][j - 1] > Mod) {
                arr[i + 1][j - 1] -= Mod;
            }
        }
    }
    int Mb = 0, b = 0;
    cin >> m;
    For(i, 0, m.size()) {
        if (m[i] == '(') ++b;
        else --b;
        Mb = min(Mb, b);
    }
    For(i, 0, n + 1) {
        if (k == 0 && i != 0) break;
        For(j, -Mb, n + 10) {
            int nb = b + j;
            if (nb < 0 || nb > 3000) continue;
            cnt += arr[i][j] * arr[n - i][nb];
            cnt %= Mod;
        }
    }
    cout << cnt << endl;
}