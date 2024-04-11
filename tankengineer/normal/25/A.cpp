//25A
#include<cstdio>

int n, t1, cnt1, cnt2, odd, even;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &t1);
        if (t1 % 2) {
            cnt1++; odd = i;
        } else {
            cnt2++; even = i;
        }
    }
    printf("%d\n", (cnt1 == 1) ? odd : even);
    return 0;
}