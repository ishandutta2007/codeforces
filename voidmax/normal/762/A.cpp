#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;

long long n, k;

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n >> k;
    long long i = 1;
    while (i * i < n) {
        if (n % i == 0) {
            --k;
            if (k == 0) {
                cout << i << endl;
                return 0;
            }
        }
        ++i;
    }
    if (i * i == n) {
        if (k == 1) {
            cout << i << endl;
            return 0;
        }
        --k;
    }
    --i;
    while (i >= 1) {
        if (n % i == 0) {
            --k;
            if (k == 0) {
                cout << n / i << endl;
                return 0;
            }
        }
        --i;
    }
    cout << -1 << endl;
}