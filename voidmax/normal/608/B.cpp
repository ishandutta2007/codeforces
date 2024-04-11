/*
 - - - - - - - -
 
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 
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

string a, b;
int cnt = 0;
long long ans = 0;
int s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    For(i, 0, b.size() - a.size() + 1) cnt += b[i] - '0';
    For(i, 0, a.size()) {
        if (a[i] == '1') {
            ans += b.size() - a.size() + 1 - cnt;
        } else {
            ans += cnt;
        }
        cnt -= b[i] - '0';
        cnt += b[b.size() - a.size() + i + 1] - '0';
    }
    cout << ans << endl;
}