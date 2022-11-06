#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
char s[maxn][maxn];

int main() {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    {
        --a; --b;
        for (int i = 0; i < 25; ++i) for (int j = 0; j < 25; ++j) s[i][j] = 'A';
        for (int i = 25; i < 50; ++i) for (int j = 0; j < 25; ++j) s[i][j] = 'B';
        for (int i = 0; i < 25 && b; i += 2) {
            int k = i % 2;
            while (k < 25 && b) s[i][k] = 'B', --b, k += 2;
        }
        for (int i = 49; i >= 25 && a; i -= 2) {
            int k = i % 2;
            while (k < 25 && a) s[i][k] = 'A', --a, k += 2;
        }
    } 
    {
        --c; --d;
        for (int i = 0; i < 25; ++i) for (int j = 25; j < 50; ++j) s[i][j] = 'C';
        for (int i = 25; i < 50; ++i) for (int j = 25; j < 50; ++j) s[i][j] = 'D';
        for (int i = 0; i < 25 && d; i += 2) {
            int k = 49 - i % 2;
            while (k >= 25 && d) s[i][k] = 'D', --d, k -= 2;
        }
        for (int i = 49; i >= 25 && c; i -= 2) {
            int k = 49 - i % 2;
            while (k >= 25 && c) s[i][k] = 'C', --c, k -= 2;
        }
    } 
    printf("50 50\n");
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) printf("%c", s[i][j]);
        puts("");
    }
}