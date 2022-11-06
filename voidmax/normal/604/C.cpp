/*
 - - - - - - - -
 
   *******
 ***********
 ***     ***
 ***
 ***
 ***
 ***
 ***     ***
 ***********
   *******
 
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

int n;
bool used[100001];
int ans[100001][2][3];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {char a; cin >> a; used[i] = a == '1';}
    ans[0][used[0]][0] = 1;
    ans[0][!used[0]][1] = 1;
    For(i, 1, n) {
        ans[i][ used[i]][0] = ans[i - 1][!used[i]][0] + 1;
        ans[i][!used[i]][1] = max(ans[i - 1][used[i]][0], ans[i - 1][used[i]][1]) + 1;
        ans[i][ used[i]][2] = max(ans[i - 1][!used[i]][1], ans[i - 1][!used[i]][2]) + 1;
        For(j, 0, 2) For(q, 0, 3) ans[i][j][q] = max(ans[i][j][q], ans[i - 1][j][q]);
    }
    int rep = 0;
    For(j, 0, 2) For(q, 0, 3) rep = max(rep, ans[n - 1][j][q]);
    cout << rep << endl;
}