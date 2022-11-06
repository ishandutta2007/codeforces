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
     
const string FILENAME = "subrev";
     
int n[2], cnt;
set <string> arr;


int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin >> n[0] >> n[1];
    for (int i = n[0]; i--;) {
        string s;
        cin >> s;
        arr.insert(s);
    }
    for (int i = n[1]; i--;) {
        string s;
        cin >> s;
        if (arr.count(s))
            ++cnt;
    }
    n[0] -= cnt;
    n[1] -= cnt;
    int c = 0;
    while (n[c] + cnt) {
        if (cnt)
            --cnt;
        else 
            --n[c];
        c ^= 1;
    }
    if (c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}