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

string FileName = "input";

typedef long long base;
int n;
vector <int> arr[4];

int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
	//write(FileName);
    //cin >> p >> q;
    cin >> n;
    For(j, 0, 2) {
        For(i, 0, n) {
            int a; cin >> a;
            if (a != 0) arr[j].pb(a);
        }
    }
    For(j, 0, 2) {
        bool OK = false;
        For(i, 0, n - 1) {
            if (arr[j][i] == 1) OK = true;
            if (OK) arr[j + 2].pb(arr[j][i]);
        }
        For(i, 0, n - 1) {
            if (arr[j + 2].size() == n - 1) break;
            arr[j + 2].pb(arr[j][i]);
        }
        //For(i, 0, n - 1) cout << arr[j + 2][i] << ' '; cout << endl;
    }
    if (arr[3] == arr[2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}