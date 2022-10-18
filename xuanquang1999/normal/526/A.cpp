using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

int n;
char a[105];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%s", &a);

    fto(i, 0, n-5) {
        int k = 1;
        while (i+4*k < n) {
            if (a[i] == '*' && a[i+k] == '*' && a[i+2*k] == '*' && a[i+3*k] == '*' && a[i+4*k] == '*') {
                printf("yes");
                return 0;
            }
            ++k;
        }
    }

    printf("no");
}