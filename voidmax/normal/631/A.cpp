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

int n;
int arr[1001][2];

int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
    cin >> n;
    For(j, 0, 2) {
        For(i, 1, n + 1) {
            cin >> arr[i][j];
            arr[i][j] |= arr[i - 1][j];
        }
    }
    cout << arr[n][0] + arr[n][1] << endl;
}