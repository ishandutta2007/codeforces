//28A
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, x[505], y[505], l[505], start, use[505], len;
bool used[505], flag;

inline int abss(int a) {return a < -a ? -a : a;}
inline int dis(int i, int j) {return x[i] == x[j] ? abss(y[i] - y[j]) : abss(x[i] - x[j]);}

int main() {
  scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    x[n] = x[0]; y[n] = y[0];
    x[n + 1] = x[1]; y[n + 1] = y[1];
    for (int i = 0; i < m; i++) scanf("%d", &l[i]);
    for (start = 0; start < 2; start++) {
        for (int i = 0; i < n + 2; i++) use[i] = -1;
        for (int i = 0; i < m; i++) used[i] = false;
        for (int j = start; j < n + start; j += 2) {
          len = dis(j, j + 1) + dis(j + 1, j + 2);
            flag = false;
            for (int k = 0; k < m; k++) {
                if (l[k] == len && !used[k]) {
                    used[k] = true;
                    use[j + 1] = k + 1;
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) break;
    }
    if (start == 2) {
        puts("NO");
    } else {
        puts("YES");
        if (start == 1) use[0] = use[n];
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", use[i]);
        }
        printf("%d\n", use[n - 1]);
    }
    return 0;
}