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

int a, b, c;

main() {
    //files(FileName);
    cin >> a >> b >> c;
    For(i, 0, c + 1) {
        if (i % a == 0 && (c - i) % b == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}