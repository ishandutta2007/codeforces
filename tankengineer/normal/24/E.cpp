//24E
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 500005;

int n, pos[N], v[N]; 
double l, r, mid, d;
bool flag;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i], &v[i]);
    }
    l = 0; r = 1e10;
  for (int t = 1; t <= 200; t++) {
        mid = (l + r) / 2; flag = false;
        d = -1e24;
        for (int i = 1; i <= n; i++) {
            if (v[i] > 0) {
                d = max(d, pos[i] + v[i] * mid);
            } else {
                if (pos[i] + v[i] * mid < d) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) r = mid; else l = mid;
    }

    if (r == 1e10) {
        puts("-1");
    } else {
        printf("%.12lf\n", r);
    }
    return 0;
}