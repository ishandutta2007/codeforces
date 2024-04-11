#include <stdio.h>
#include <math.h>
#include <memory.h>

using namespace std;

const int N = 5005;

int n, tt;
double f[N], ff[N];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &tt);
    f[0] = 1;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int p, t;
        scanf("%d%d", &p, &t);
        double pp = (100 - p) * 1.0 / 100;
        double pw = 1;
        for (int i = 1; i + 1 <= t; i++) {
            pw *= pp;
            if (pw < 1e-15) {
                pw = 0;
                break;
            }
        }
        double sum = 0;
        for (int j = 0; j + 1 < t; j++) {
            ff[j] = sum * (1 - pp);
            ans += ff[j];
            sum *= pp;
            sum += f[j];
            if (sum < 1e-15) sum = 0;
        }
        ff[t - 1] = sum * (1 - pp);
        ans += ff[t - 1];
        sum *= pp;
        sum += f[t - 1];
        sum -= f[0] * pw;
        
        for (int j = t; j <= tt; j++) {
            ff[j] = sum * (1 - pp);
            ff[j] += f[j - t] * pw;
            ans += ff[j];
            sum *= pp;
            sum += f[j];
            sum -= f[j - t + 1] * pw;
            if (sum < 1e-15) sum = 0;
        }
        pw = 1;
        memcpy(f, ff, sizeof(ff));
    }
    printf("%.10lf\n", ans);
}