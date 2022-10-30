#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include <queue>
#define LL long long

using namespace std;

int a[200100], b[200100], next[200100];
int n, w;

void getnext () {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < w) {
        if (j == -1 || b[i] == b[j]) {
            i++, j++;
            next[i] = j;
        } else j = next[j];
    }
}

int kmp () {
    int i = 0, j = 0, num = 0;
    while (i < n) {
        if (j == -1) {
            i++, j = 0;
        } else if (a[i] == b[j]) {
            i++, j++;
        } else j = next[j];
        if (j >= w) {
            j = next[j];
            num++;
        }
    }
    return num;
}

int main () {
    cin >> n >> w;
    int p, q;
    cin >> p;
    for (int i = 2; i <= n; i++) {
        scanf ("%d", &q);
        a[i - 2] = q - p;
        p = q;
    }
    cin >> p;
    for (int i = 2; i <= w; i++) {
        scanf ("%d", &q);
        b[i - 2] = q - p;
        p = q;
    }
    if (n < w) {
        cout << 0;
        return 0;
    }
    if (w == 1) {
        cout << n;
        return 0;
    }
    n--, w--;
    getnext ();
    cout << kmp() << endl;
}