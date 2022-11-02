#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

char s[N];
char c[10][10] = { "AB", "BA", "ABA", "BAB", "ABAB", "BABA" };
int cnt[10];

int jug (int x, int k) {
    for (int i = 0; c[k][i]; i++) {
        if (s[x + i] != c[k][i]) return 0;
    }
    return 1;
}

void y () { cout << "YES\n"; }
void o () { cout << "NO\n"; }

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s);
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < 6; j++) if (jug (i, j)) cnt[j]++;
    }
    if (cnt[0] == 0 || cnt[1] == 0) o ();
    else if (cnt[0] > 2 || cnt[1] > 2) y ();
    else if (cnt[0] == 2 && cnt[1] == 2) y ();
    else if (cnt[0] == 2 && cnt[1] == 1) {
        if (cnt[4]) o ();
        else y ();
    } else if (cnt[0] == 1 && cnt[1] == 2) {
        if (cnt[5]) o();
        else y ();
    } else {
        if (cnt[2] || cnt[3]) o ();
        else y ();
    }
}