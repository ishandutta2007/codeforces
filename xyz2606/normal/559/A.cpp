#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    double area(0.5 * b * c * sqrt(3) / 2 + 0.5 * e * f * sqrt(3) / 2 + 0.5 * (a + d) * (b + c) * sqrt(3) / 2);
    printf("%d\n", (int)(area / sqrt(3) * 4 + 0.5));
}