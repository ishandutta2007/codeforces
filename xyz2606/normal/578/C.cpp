#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(222222);
int a[N];
double calc(const double & delta, int n) {
    double cur(0), ans(0), cur1(0);
    for(int i(1); i <= n; i++) {
        cur = max(cur + a[i] - delta, 0.);
        ans = max(ans, cur);
        cur1 = max(cur1 - a[i] + delta, 0.);
        ans = max(ans, cur1);
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i(1); i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double le(-11111), ri(11111);
    for(int i(1); i <= 200; i++) {
        double mid1((le * 2 + ri) / 3), mid2((le + ri * 2) / 3);
        if(calc(mid1, n) < calc(mid2, n)) {
            ri = mid2;
        }else {
            le = mid1;
        }
    }
    printf("%.10f\n", calc((le + ri) / 2, n));
}