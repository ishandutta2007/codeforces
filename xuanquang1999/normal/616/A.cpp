#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define maxN 1000005

int m, n;
char a[maxN], b[maxN];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%s", a);
    scanf("%s", b);

    m = strlen(a); n = strlen(b);
    int i = 0, j = 0;
    while (a[i] == '0' && i < m-1) ++i;
    while (b[j] == '0' && j < n-1) ++j;
    if (m-i < n-j) {
        puts("<");
        return 0;
    }
    if (m-i > n-j) {
        puts(">");
        return 0;
    }
    fto(k, 0, m-i-1) {
        if (a[i+k] < b[j+k]) {
            puts("<");
            return 0;
        }
        if (a[i+k] > b[j+k]) {
            puts(">");
            return 0;
        }
    }
    puts("=");

    return 0;
}