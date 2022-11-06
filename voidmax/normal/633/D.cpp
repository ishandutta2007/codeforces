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

string FileName = "train";

int n;
set <int> arr;
multiset <int> all;
int Max = 1;

void check(int a, int b) {
    if (a == b && a == 0) {
        Max = max(Max, (int)all.count(0));
        return;
    }
    vector <int> arr;
    if (all.count(a) == 0) return;
    all.erase(all.find(a));
    if (all.count(b) == 0) {
        all.insert(a);
        return;
    }
    all.erase(all.find(b));
    arr.pb(a); arr.pb(b);
    while (true) {
        int c = a + b;
        swap(a, c);
        swap(a, b);
        if (all.count(b) == 0) break;
        all.erase(all.find(b));
        arr.pb(b);
    }
    Max = max(Max, (int)arr.size());
    For(i, 0, arr.size()) {
        all.insert(arr[i]);
    }
}


main() {
    //files(FileName);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        arr.insert(a);
        all.insert(a);
    }
    for(int i: arr) {
        for(int j: arr) {
            check(i, j);
        }
    }
    cout << Max << endl;
}