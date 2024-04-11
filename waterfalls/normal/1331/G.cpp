#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> hi;
    for (int i=1;i<=11;i++) {
        int x;
        scanf("%d", &x);
        hi.push_back(x);
    }
    for (int i=11;i>=1;i--) {
        double a = sqrt(abs(hi[i-1]));
        double b = (double) hi[i-1]*hi[i-1]*hi[i-1] * 5;
        double res = a + b;
        if (400 >= res) {
            printf("f(%d) = %.2f\n", hi[i-1], res);
        } else {
            printf("f(%d) = MAGNA NIMIS!\n", hi[i-1]);
        }
    }
}