#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200200;
const int INF = (int)2e9 + 10;
int ans = INF;
int n;
vector<pii> a[N], b[N];
int c[N];
int d;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i = 0; i < N; i++)
        c[i] = INF;
    scanf("%d%d", &n, &d);
    while(n--) {
        int l, r, w;
        scanf("%d%d%d", &l, &r, &w);
        a[l].push_back(mp(r - l + 1, w));
        b[r].push_back(mp(r - l + 1, w));
    }
    for (int i = 0; i < N; i++) {
        for (pii t : a[i]) {
            if (t.first >= d) continue;
            if (c[d - t.first] < INF)
                ans = min(ans, c[d - t.first] + t.second);
        }
        for (pii t : b[i])
            c[t.first] = min(c[t.first], t.second);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}