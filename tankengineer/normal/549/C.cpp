#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, c;

int main() {
    scanf("%d%d", &n, &k);
    k = n - k;
    c = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        c += a % 2;
    }
/*
for (int nn = 1; nn <= 50; ++nn) {
    for (int kk = 0; kk <= nn; ++kk) {
        for (int cc = 0; cc <= nn; ++cc) {
            n = nn, k = nn - kk, c = cc;
            */
    int noEvenWin = (n - k) % 2, noOddWin = 0;
    int last = k % 2;
    for (int i = 1; i < k; ++i) {
        if (c == 0) {
            --n;
            continue;
        } 
        if (c == n) {
            --c;
            --n;
            continue;
        }
        if (i % 2 == last) {
            if (last != noEvenWin && last != noOddWin) {
                if (c > n - c) {
                    --c;
                }
            }
            if (last != noEvenWin && last == noOddWin) {
                if (c >= n - c) {
                    --c;
                }
            }
            if (last == noEvenWin && last != noOddWin) {
                if (c > n - c) {
                    --c;
                }
            }
            if (last == noEvenWin && last == noOddWin) {
                if (c > n - c) {
                    --c;
                }
            }
        } else {
            if (last != noEvenWin && last != noOddWin) {
                if (c < n - c) {
                    --c;
                }
            }
            if (last != noEvenWin && last == noOddWin) {
            }
            if (last == noEvenWin && last != noOddWin) {
                --c;
            }
            if (last == noEvenWin && last == noOddWin) {
            }
        }
        --n;
    }
    int win = -1;
    if (k == 0) {
        win = c % 2;
    } else {
        if (c == 0) {
            win = noOddWin;
        } else if (c == n) {
            win = noEvenWin;
        } else {
            win = last;
        }
    }
    puts(win ? "Stannis" : "Daenerys");
    /*printf("%d", win);

        }
    printf("\n");}}*/
    return 0;
}