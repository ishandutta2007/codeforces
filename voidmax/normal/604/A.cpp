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
#define x first
#define y second

using namespace std;

long long arr[5] = {500, 1000, 1500, 2000, 2500};
long long t[5], w[5], h[2];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    For(i, 0, 5) cin >> t[i];
    For(i, 0, 5) cin >> w[i];
    For(i, 0, 2) cin >> h[i];
    For(i, 0, 5) ans += max(75 * arr[i], (250 - t[i]) * arr[i] - 50 * 250 * w[i]);
    ans += h[0] * 25000; ans -= h[1] * 12500;
    cout << ans / 250 << endl;
}