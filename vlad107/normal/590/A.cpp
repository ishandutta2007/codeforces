#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = -1;
const int INF = 1e9 + 19;

pair< int, vector<int> > brute(vector<int> a) {
    for (int it = 0; it < 1e5; it++) {
        vector<int> b = a;
        for (int i = 1; i + 1 < (int)b.size(); i++) {
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            cnt[a[i - 1]]++;
            cnt[a[i]]++;
            cnt[a[i + 1]]++;
            if (cnt[0] > cnt[1]) b[i] = 0; else b[i] = 1;
        }
        if (b == a) return mp(it, a);
        a = b;
    }
    assert(false);
}

pair< int, vector<int> > solve(vector<int> a) {
    int i = 1;
    int ans = 0;
    while (i + 1 < (int)a.size()) {
        if (a[i] == a[i - 1]) { ++i; continue; }
        if (a[i] == a[i + 1]) { ++i; continue; }
        int j = i;
        while ((j + 1 < (int)a.size()) && (a[j] != a[j + 1])) ++j;
        int l = i, r = j;
        int cnt = 0;
        // cerr << l << " " << r << endl;
        while (l < r) {
            a[l] = a[l - 1]; ++l;
            a[r - 1] = a[r]; --r;
            cnt++;
        }
        if ((l == r) && (a[l - 1] != a[l]) && (a[l + 1] != a[l])) {
            a[l] = a[l - 1];
            ++cnt;
        }
        ans = max(ans, cnt);
        i = j;
    }
    return mp(ans, a);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // while (1) {
    //  int n = 2;
    //  vector<int> a(n);
    //  for (int i = 0; i < n; i++) a[i] = rand() % 2;
    //  pair< int, vector<int> > cor = brute(a);
    //  pair< int, vector<int> > ans = solve(a);
    //  if (cor != ans) {
    //      cout << n << endl;
    //      for (int i = 0; i < n; i++) cout << a[i] << " ";
    //      cout << endl;
    //      cout << cor.fr << " " << ans.fr << endl;
    //      for (int i = 0; i < n; i++) cout << cor.sc[i] << " " << ans.sc[i] << endl;
    //      assert(false);
    //  } else cout << n << " " << "Ok" << endl;
    // }
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    pair< int,  vector<int> > ans = solve(a);
    printf("%d\n", ans.fr);
    for (int i = 0; i < (int)ans.sc.size(); i++) printf("%d ", ans.sc[i]);
    puts("");
}