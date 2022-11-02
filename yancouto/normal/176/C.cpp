#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
        int i, j, x[2], y[2];
        scanf("%*d %*d");
        for(i = 0; i < 2; i++)
                scanf("%d %d", &x[i], &y[i]);
        x[1] = abs(x[1] - x[0]) + 1;
        y[1] = abs(y[1] - y[0]) + 1;
        for(i = 0; i < 4; i++) {
                for(j = 0; j < 2; j++) {
                        // j = 1 updown
                        int d = 4;
                        if((i & 1) == j) d++;
                        if((i & 2) == (j<<1)) d++;
                        if(d <= (j?y:x)[1]) break;
                }
                if(j == 2) break;
        }
        if(i < 4) puts("First");
        else puts("Second");
}