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

typedef unsigned long long base;

base n;
int arr[5];

int main() {
    //ios::sync_with_stdio(false);
    cin >> n;
    arr[4] = n % 10; n /= 10;
    arr[3] = n % 10; n /= 10;
    arr[2] = n % 10; n /= 10;
    arr[1] = n % 10; n /= 10;
    arr[0] = n % 10; n /= 10;
    swap(arr[1], arr[2]);
    swap(arr[2], arr[4]);
    n += arr[4] + arr[3] * 10 + arr[2] * 100 + arr[1] * 1000 + arr[0] * 10000;
    base ans = 1;
    ans *= n; ans %= 100000;
    ans *= n; ans %= 100000;
    ans *= n; ans %= 100000;
    ans *= n; ans %= 100000;
    ans *= n; ans %= 100000;
    arr[4] = ans % 10; ans /= 10;
    arr[3] = ans % 10; ans /= 10;
    arr[2] = ans % 10; ans /= 10;
    arr[1] = ans % 10; ans /= 10;
    arr[0] = ans % 10; ans /= 10;
    cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4];
}