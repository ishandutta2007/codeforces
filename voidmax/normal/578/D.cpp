/*
 - - - - - - - -
 
 ********
 **********
 ***    ****
 ***     ***
 ***     ***
 ***     ***
 ***     ***
 ***    ****
 **********
 ********
 
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
#define pb push_back
#define inf 1e9
#define x first
#define y second

using namespace std;

int n, m, e;
long long ans = 0;
string s;

int main () {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s; s += '#';
    For(i, 0, n) if (s[i] != s[i + 1]) ans += n * (m - 1);
    For(i, 0, n - 1) {
        if (s[i] == s[i + 1]) continue;
        e = max (e, i + 1);
        while (e < n - 1 && s[e + 1] == s[e - 1]) e++;
        ans -= e - i;
    }
    cout << ans << endl;
}