/*
 - - - - - - - -
 
 *********
 **********
 ***     ***
 ***     ***
 **********
 **********
 ***     ***
 ***     ***
 **********
 *********
 
 - - - - - - - -
 */

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
#define inf 1e9
#define x first
#define y second

using namespace std;

const int SizeOf = 3e5;
int n, k, X;
long long s[SizeOf + 1];
long long pref[SizeOf + 1];
long long suf[SizeOf + 1];
long long modification;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> X; modification = 1; For(i, 0, k) modification *= X;
    For(i, 0, n) cin >> s[i];
    For(i, 0, n)  pref[i + 1] = pref[i] | s[i];
    For(i, -n, 0) suf[-i] = suf[1 - i] | s[-i];
    long long ans = 0;
    For(i, 0, n) ans = max(ans, pref[i] | suf[i + 1] | (s[i] * modification));
    cout << ans;
}