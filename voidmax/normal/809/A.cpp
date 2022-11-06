// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include "grader.h"
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
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define read(FILENAME) assert(freopen((FILENAME + ".in").c_str(), "r", stdin))
#define write(FILENAME) assert(freopen((FILENAME + ".out").c_str(), "w", stdout))
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
template <typename A, typename B> void chkmin(A &x, B y) {if (x > y) x = y;}
template <typename A, typename B> void chkmax(A &x, B y) {if (x < y) x = y;}
     
typedef pair <int, int> point;
     
const string FILENAME = "input";
const int MAXN = 4e5, p = 1e9 + 7;
     
int sum(int a, int b) {
    a += b;
    if (a >= p)
        a -= p;
    return a;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int powx(int a, long long b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int n;
int ans = 0;
long long suf[MAXN], pref[MAXN];
vector <int> arr;

int main() {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + i;
    }
    for (int i = n; i--;) {
        suf[i] = suf[i + 1] + i;
    }
    for (int i = 0; i < n; ++i) {
        int c = sum(powx(2, i), p - 1);
        ans = sum(ans, mul(arr[i], c));
        c = sum(powx(2, n - i - 1), p - 1);
        ans = sum(ans, p - mul(arr[i], c));
    }
    cout << ans << endl;
}