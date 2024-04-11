#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 1e6 + 111;
const long long INF = 1e18;

long long f[3], ff[3], ans;
int c0, c1;
int a[N], n;
 
void solve() {
    // take 1
    for (int diff = -1; diff <= 1; diff++) {
        vector<int> v;
        int u = a[0] + diff;
        int uu = u;
        for (int i = 2; i * i <= uu; i++) {
            if (u % i == 0) {
                v.push_back(i);
                while (u % i == 0) u /= i;
            }
        }
        if (u != 1) v.push_back(u);
//        cerr << uu << ": ";
//        for (int i = 0; i < (int)v.size(); i++) cerr << v[i] << " ";
//        cerr << endl;
        for (int i = 0; i < (int)v.size(); i++) {
            int x = v[i];
            for (int j = 0; j < 3; j++) f[j] = INF;
            f[0] = 0;
            if (a[0] % x != 0) f[0] = c1;
            for (int e = 1; e < n; e++) {
               bool can = (((a[e] - 1) % x == 0) || ((a[e] + 1) % x == 0) || (a[e] % x == 0));
               bool cool = (a[e] % x == 0);
               for (int j = 0; j < 3; j++) ff[j] = INF;
               for (int j = 0; j < 3; j++) {
                  if (f[j] != INF) {
                    for (int k = j; k < 3; k++) {
                        if ((k != 1) && (!can)) continue;
                        long long cur = f[j];
                        if (k == 1) cur += c0; else
                        if (!cool) cur += c1;
                        ff[k] = min(ff[k], cur);
                    }
                  }
               }
               swap(f, ff);
            }
            for (int i = 0; i < 3; i++) ans = min(ans, f[i]);
        }
    }
}
 
int main(){
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &c0, &c1);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ans = INF;
    solve();
    reverse(a, a + n);
    solve();
    cout << ans << endl;
    return 0;
}