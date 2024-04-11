#include <map>
#include <set>
#include <vector>
#include <stdio.h>

#define pb push_back

const int N = 2e5;

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector< int > x(n);
    std::map<int,int> gnom;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        gnom[x[i]] = i + 1;
    }
    std::set<int> s;
    for (int i = 0; i < x.size(); i++) s.insert(x[i]);
    for (int i = 0; i < m; i++) {
        int nom, l;
        scanf("%d%d", &nom, &l);
        int cur = x[nom - 1];
        while (1) {
            auto prv = s.lower_bound(cur - l);
            auto nxt = s.upper_bound(cur + l);
            --nxt;
            if (*nxt == cur) {
                if (*prv == cur) break;
                if ((*nxt == cur) && (l >= 2 * (cur - *prv))) l %= 2 * (cur - *prv); else {
                    l -= (cur - *prv);
                    cur = *prv;
                }
            } else {
                if ((*prv == cur) && (l >= 2 * (*nxt - cur))) l %= 2 * (*nxt - cur); else {
                    l -= (*nxt - cur);
                    cur = *nxt;
                }
            }
        }
        printf("%d\n", gnom[cur]);
    }
}