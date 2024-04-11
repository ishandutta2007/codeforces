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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

long long n, k;

long long res(vector <long long> &p, int i, bool flag, long long mod) {
    if (i == p.size()) {
        if (flag)
            return -mod;
        return mod;
    }
    return res(p, i + 1, flag, mod) + res(p, i + 1, flag ^ 1, mod / p[i]);

}

long long f(long long n) {
    if (n == 1) return 1;
    vector <long long> p;
    long long m = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            p.pb(i);
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1) p.pb(n);
    return res(p, 0, 0, m);
}

long long g(long long n) {
    long long cnt = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt += f(i);
            if (n != i * i) {
                cnt += f(n / i);
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    cin >> n >> k;
    long long lst = 0;
    n = f(g(n));
    --k;
    int s = 0;
    while (k && n != 1) {
        if (s & 1) 
            n = f(n);
        else 
            n = g(n);
        --k, ++s;
    }
    cout << n % (1000000007) << endl;
}