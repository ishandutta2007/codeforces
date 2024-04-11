#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    int m = 32;
    vector<vector<int>> a(m, vector<int>(m));
    for(int i = 2; i <= 32; i <<= 1) {
        int j = i / 2;
        // [0, j), [j, i)
        for(int x = j; x < i; ++x) {
            for(int y = 0; y < j; ++y) {
                a[x][y] = (j * j) | a[i - 1 - x][y];
                a[y][x] = (j * j * 2) | a[y][i - 1 - x];
            }
            for(int y = j; y < i; ++y) {
                a[x][y] = (j * j * 3) | a[i - 1 - x][i - 1 - y];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            cout << (a[i][j] ^ a[i][j + 1]) << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << (a[i][j] ^ a[i + 1][j]) << " ";
        }
        cout << endl;
    }
    int h = 0;
    while(q--) {
        int d;
        cin >> d;
        int x = -1, y = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] == (h ^ d)) {
                    x = i;
                    y = j;
                }
            }
        }
        cout << x + 1 << " " << y + 1 << endl;
        h ^= d;
    }
}