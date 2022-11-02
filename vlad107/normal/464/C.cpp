#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

#define next blablabla

const int N = 500500;
const int BASE = 1000000007;

string s;
int t;
char ct[N];
string p[N];
int next[10], len[10];

int pw(int x, int y, int b) {
    int res = 1;
    while (y) {
        if (y & 1) {
            res = (res * 1LL * x) % b;
        }
        x = (x * 1LL * x) % b;
        y >>= 1;
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ct[0] = '0';
    cin >> p[0];
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string e;
        cin >> e;
        ct[i] = e[0];
        e.erase(0, 3);
        p[i] = e;
        // cerr << ct[i] << " " << p[i] << endl;
    }
    for (int i = 0; i < 10; i++) {
        next[i] = i;
        len[i] = 1;
    }
    for (int i = t; i >= 0; i--) {
        int x = ct[i] - '0';
        int cl = 0;
        int cn = 0;
        for (int j = (int)p[i].size() - 1; j >= 0; j--) {
            int o = p[i][j] - '0';
            cn = (cn + next[o] * 1LL * pw(10, cl, BASE)) % BASE;
            cl = (cl + len[o]);
            if (cl >= BASE - 1) {
                cl -= BASE - 1;
            }
        }
        next[x] = cn;
        len[x] = cl;
    }
    cout << next[0] << endl;
}