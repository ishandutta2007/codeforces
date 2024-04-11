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

int n, k, a, b, q;

struct tree {
    base NoMore;
    base arr[400000];
    int f(int i) {
        return i - (i & (i - 1));
    }
    base get(int i) {
        base ans = 0;
        while (i > 0) {
            ans += arr[i];
            i -= f(i);
        }
        return ans;
    }
    void sum(int i, int s) {
        base X = get(i) - get(i - 1);
        s = min((base)s, NoMore - X);
        while (i <= n) {
            arr[i] += s;
            i += f(i);
        }
    }
};

tree A, B;

int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
	//write(FileName);
    //cin >> p >> q;
    cin >> n >> k >> a >> b >> q;
    A.NoMore = b;
    B.NoMore = a;
    For(i, 0, q) {
        int t;
        cin >> t;
        if (t == 2) {
            int p; cin >> p;
            base cnt = 0;
            cnt += A.get(p - 1);
            cnt -= B.get(p + k - 1);
            cnt += B.get(n);
            cout << cnt << endl;
        } else {
            int p, s; cin >> p >> s;
            A.sum(p, s);
            B.sum(p, s);
        }
    }

}