//  buckets, sqrt, data structures, idea, 4
#include <cstdio>

const int N = 123456;
const int B = 316;
int next[N];
int jumps[N];
int v[N];

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &v[i]);
    for (int i = n-1; i >= 0; --i) {
        next[i] = v[i] + i;
        jumps[i] = 1;
        if (next[i] < n && next[next[i]] < n && next[i] / B == i / B)
            jumps[i] += jumps[next[i]], next[i] = next[next[i]];
    }
    int code, hole, val;
    for (int i = 0; i < m; ++i) {
        scanf ("%d", &code);
        if (code == 0) {
            scanf ("%d%d", &hole, &val);
            hole--;
            v[hole] = val;
            for (int j = hole; ; --j) {
                next[j] = v[j] + j;
                jumps[j] = 1;
                if (next[j] < n && next[next[j]] < n && next[j] / B == j / B)
                    jumps[j] += jumps[next[j]], next[j] = next[next[j]];
                if (j % B == 0) break;
            }
        } else {
            scanf ("%d", &hole);
            hole--;
            int total = 0;
            while (next[hole] < n) {
                total += jumps[hole];
                hole = next[hole];
            }
            printf ("%d %d\n", hole+1, total+1);
        }
    }
	return 0;
}