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

base n;
int arr[4];
int main() {
    //ios::sync_with_stdio(false);
    cin >> n; n *= -1; n %= 360;
    if (n < 0) n += 360;
    arr[0] = n;
    arr[1] = (n + 90) % 360;
    arr[2] = (n + 180) % 360;
    arr[3] = (n + 270) % 360;
    arr[0] = min(360 - arr[0], arr[0]);
    arr[1] = min(360 - arr[1], arr[1]);
    arr[2] = min(360 - arr[2], arr[2]);
    arr[3] = min(360 - arr[3], arr[3]);
    if (min(min(arr[0], arr[1]), min(arr[2], arr[3])) == arr[0]) {
        cout << 0; return 0;
    }
    if (min(min(arr[0], arr[1]), min(arr[2], arr[3])) == arr[1]) {
        cout << 1; return 0;
    }
    if (min(min(arr[0], arr[1]), min(arr[2], arr[3])) == arr[2]) {
        cout << 2; return 0;
    }
    if (min(min(arr[0], arr[1]), min(arr[2], arr[3])) == arr[3]) {
        cout << 3; return 0;
    }
}