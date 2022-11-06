/*
 - - - - - - - -
 
  *********
 ***********
 ***     ***
 ***     ***
 ***     ***
 ***********
 ***********
 ***     ***
 ***     ***
 ***     ***
 
 - - - - - - - -
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int n, p, q;
string a;
int cnt[101];
int used[101];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p >> q >> a;
    used[n] = -1;
    Out(i, n + 1, 0) {
        if (!used[i]) continue;
        if (i - p >= 0 && !used[i - p]) {used[i - p] = p; cnt[i - p] = cnt[i] + 1;}
        if (i - q >= 0 && !used[i - q]) {used[i - q] = q; cnt[i - q] = cnt[i] + 1;}
    }
    if (!used[0]) {
        cout << -1 << endl;
    } else {
        cout << cnt[0] << endl;
        int i = 0;
        while (used[i] != -1) {
            For(j, 0, used[i]) cout << a[i + j];
            i += used[i];
            cout << endl;
        }
    }
}