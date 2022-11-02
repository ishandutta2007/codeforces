#include <bits/stdc++.h>
using namespace std;

int ev[3009];
int cs[70][2];
int main() {
    int i, j, p, q, l, r, a, b;
    scanf("%d %d %d %d", &p, &q, &l, &r);
    for(i = 0; i < p; i++) {
        scanf("%d %d", &a, &b);
        ev[a]++; ev[b+1]--;
    }
    for(i = 0; i < q; i++)
        scanf("%d %d", &cs[i][0], &cs[i][1]);
    int s = 0;
    for(i = 0; i <= 3003; i++) {
        s += ev[i];
        ev[i] = s;
        if(i > 0) ev[i] += ev[i - 1];
    }
    int tot = 0;
    for(i = l; i <= r; i++) {
        for(j = 0; j < q; j++)
            if(ev[i + cs[j][1]] - (((i + cs[j][0] - 1) < 0)? 0 : ev[i + cs[j][0] - 1]) > 0)
                break;
        if(j < q) tot++;
    }
    printf("%d\n", tot);
}