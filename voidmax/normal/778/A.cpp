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

string a, b;
int p[200001];
bool used[200001];

bool check(int M) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        used[i] = 0;
    for (int i = 0; i < M; ++i)
        used[p[i]] = true;
    for (int i = 0; i < a.size(); ++i) {
        if (used[i] || cnt == b.size()) 
            continue;
        if (a[i] == b[cnt])
            ++cnt;
    }
    return cnt == b.size();
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        cin >> p[i];
        --p[i];
    }
    int L = 0, R = a.size();
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << L << endl;
}