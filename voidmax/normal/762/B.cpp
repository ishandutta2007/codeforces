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

const string USB = "USB";

int a[2], b, m;
vector <pair <int, bool>> arr;

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> a[0] >> a[1] >> b;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int c;
        string s;
        cin >> c >> s;
        arr.pb({c, s != USB});
    }
    sort(arr.begin(), arr.end());
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < m; ++i) {
        if (a[arr[i].y]) {
            --a[arr[i].y];
            ++cnt1;
            cnt2 += arr[i].x;
        } else if (b) {
            --b;
            ++cnt1;
            cnt2 += arr[i].x;
        }
    }
    cout << cnt1 << ' ' << cnt2 << endl;
}