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
long long a, b;

int arr[64][2];
int cnt = 0;
int block = 0;

int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
	//write(FileName);
    //cin >> p >> q;
    cin >> a >> b;
    if (a == b) block += 2;
    For(i, 0, 64) {
        arr[i][0] = a & 1;
        a >>= 1;
    }
    For(i, 0, 64) {
        arr[i][1] = b & 1;
        b >>= 1;
    }
    For(i, 0, 64) {
        if (arr[i][1]) {
            --arr[i][0];
            ++cnt;
        }
    }
    For(i, 0, 63) {
        while (arr[i][0] < 0) {
            arr[i][0] += 2;
            --arr[i + 1][0];
        }
    }
    if (arr[63][0] < 0 || arr[0][0]) {
        cout << 0 << endl;
        return 0;
    }
    For(i, 0, 64) {
        if (arr[i][0]) {
            if (arr[i - 1][1]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ((base)1 << cnt) - block;
}