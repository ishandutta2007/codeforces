#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXK 1005

using namespace std;

char s[MAXN];
int n, l, k;
char sol[MAXK][MAXK];

int main() {
    scanf("%d %d %d", &n, &l, &k);
    scanf("%s", s);
    
    sort(s, s+n*l);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            sol[i][j] = '?';
        }
    }
    int sit = 0;

    int top = 1;
    for (int iter = 1; iter <= l; iter++) {
        for (int i = top; i <= k; i++) {
            sol[i][iter] = s[sit];
            sit++;
        }
        top = k;
        while (top-1 >= 1 && sol[top-1][iter] == sol[top][iter]) top--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            if (sol[i][j] == '?') {
                sol[i][j] = s[sit]; sit++;
            }
            printf("%c", sol[i][j]);
        }
        printf("\n");
    }
    return 0;
}