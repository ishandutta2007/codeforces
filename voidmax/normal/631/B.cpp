#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <time.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, m, k;
pair <int, int> arr[100000][2];

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    For(i, 0, k) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[b - 1][a - 1] = {c, i + 1};
    }
    For(i, 0, n) {
        For(j, 0, m) {
            if (arr[i][0].y > arr[j][1].y) {
                cout << arr[i][0].x << ' ';
            } else {
                cout << arr[j][1].x << ' ';
            }
        }
        cout << endl;
    }
}