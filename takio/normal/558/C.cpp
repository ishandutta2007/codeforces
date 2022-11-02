#include <bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define LL long long
#define xx first
#define yy second
using namespace std;

const int N = 100005, C = 32;
const LL INF = 1LL << 60;

set <int> st;
int r[N], c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf ("%d", &a);
        int cnt = 0;
        a *= 2;
        a++;
        while (a != 1) {
            if (a % 2 == 1) {
                a /= 2;
                int t = a, tc = cnt;
                while (t < N) {
//                    cout << i << ' ' << t << ' ' << tc << endl;
                    r[t] += tc;
                    c[t]++;
                    tc++;
                    t *= 2;
                }
            } else {
                a /= 2;
                r[a] += cnt;
                c[a]++;
            }
            cnt++;
        }
    }
    int mn = 1e9;
    for (int i = 1; i < N; i++) if (c[i] == n) {
        mn = min (mn, r[i]);
    }
    cout << mn << endl;
}