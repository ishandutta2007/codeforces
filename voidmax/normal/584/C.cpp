#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define pb push_back
#define inf 1e9
#define x first
#define y second
#define ins insert

using namespace std;

int n, t;
int cnt;
string a, b;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t >> a >> b; t = n - t;
    For(i, 0, n) {
        if (cnt != t) {
            if (a[i] == b[i]) {
                ++cnt;
                ans += a[i];
            } else {
                set <char> c; c.ins('a'); c.ins('b'); c.ins('c');
                c.erase(a[i]); c.erase(b[i]);
                ans += *c.begin();
            }
        } else {
            set <char> c; c.ins('a'); c.ins('b'); c.ins('c');
            c.erase(a[i]); c.erase(b[i]);
            ans += *c.begin();
        }
    }
    if (cnt != t) {
        cnt = t - cnt;
        cnt <<= 1;
        For(i, 0, n) {
            if (cnt == 0) {
                break;
            }
            if (a[i] != b[i]) {
                ans[i] = cnt & 1 ? a[i] : b[i];
                --cnt;
            }
        }
        if (cnt == 0) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << ans << endl;
    }
}