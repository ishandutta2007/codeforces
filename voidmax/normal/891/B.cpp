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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 3001;

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int n;
int a[MAXN];
int b[MAXN];
vector<int> id;

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        id.pb(i);
    }
    sort(id.begin(), id.end(), cmp);
    for (int i = 0; i < n; ++i) {
        b[id[i]] = a[id[(i + 1) % n]];
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
}