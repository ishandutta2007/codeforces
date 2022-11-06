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


typedef long long base;
int d, n, m;
base cnt = 0;
vector <pair <int, int>> bush;
int NextLess[200001];
vector <int> arr;

int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
	//write(FileName);
    //cin >> p >> q;
    cin >> d >> n >> m;
    bush.pb({d, 0});
    For(i, 0, m) {
        int a, b; cin >> a >> b;
        bush.pb({a, b});
    }
    int LastCoor = 0;
    int MyE = n;
    sort(bush.begin(), bush.end());
    For(i, 0, bush.size()) {
        int Last = arr.size(); --Last;
        while (Last != -1 && bush[arr[Last]].y >= bush[i].y) {
            NextLess[arr[Last]] = bush[i].x - bush[arr[Last]].x;
            arr.pop_back(); --Last;
        }
        arr.pb(i);
    }
    For(i, 0, m + 1) {
        MyE -= bush[i].x - LastCoor;
        LastCoor = bush[i].x;
        if (MyE < 0) {
            cout << -1 << endl;
            return 0;
        }
        if (bush[i].x == d) {
            cout << cnt << endl;
            return 0;
        }
        int NMyE = MyE;
        NMyE = min(n, NextLess[i]);
        cnt += (base)(max(0, NMyE - MyE)) * bush[i].y;
        MyE = max(MyE, NMyE);
    }
}