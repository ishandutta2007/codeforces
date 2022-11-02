#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
priority_queue<pair<long long, int>> e;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        e.push(make_pair(-1, i));
    }
    for (int i = 0; i < n; i++) {
        int s, m;
        scanf("%d%d", &s, &m);
        pair<long long, int> cur = e.top();
        cur.first *= -1;
        e.pop();
        if (s > cur.first) cur.first = s;
        cur.first += m;
        printf("%I64d\n", cur.first);
        e.push(make_pair(-cur.first, cur.second));
    }
}