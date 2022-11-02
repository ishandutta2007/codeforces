#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 200100;
char s[N];
int t[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s + 1);
    int len = strlen (s + 1);
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        a = min (a, len - a + 1);
        t[a] ^= 1;
    }
    int now = 0;
    for (int i = 1; i * 2 <= len; i++) {
        now ^= t[i];
        if (now) swap (s[i], s[len - i + 1]);
    }
    printf ("%s", s + 1);
}