#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 111;
int a[N][N];
int b[N], c[N];
int n, m;
bool rev = false;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    if (n > m) {
        rev = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(a[i][j], a[j][i]);
        swap(n, m);
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[i][0];
        for (int j = 0; j < m; j++)
            b[i] = min(b[i], a[i][j]);
        for (int j = 0; j < m; j++)
            a[i][j] -= b[i];
    }
    for (int j = 0; j < m; j++) {
        c[j] = a[0][j];
        for (int i = 0; i < n; i++) {
            if (a[i][j] != c[j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += b[i];
    for (int i = 0; i < m; i++)
        ans += c[i];
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        while(b[i]--) {
            if (rev)
                printf("col ");
            else
                printf("row ");
            printf("%d\n", i + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        while(c[i]--) {
            if (rev)
                printf("row ");
            else
                printf("col ");
            printf("%d\n", i + 1);
        }
    }

    return 0;
}