#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(b > a) {
        printf("-1\n");
    }else if(a == b) {
        printf("%d.000000000\n", a);
    }else {
        int k((a - b) / b);
        if(k & 1) {
            k--;
        }
        double ans1(1. * (a - b) / k);
        k = (a + b) / b;
        if(k & 1) {
            k--;
        }
        double ans2(1. * (a + b) / k);
        printf("%.9f\n", min(ans1, ans2));
    }
}