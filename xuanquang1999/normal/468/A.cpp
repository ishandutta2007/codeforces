//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define maxB 20
#define oo 1000000007
#define EPS 10e-9

struct NodeType {
    int v, sum;
};

int n;

int main() {
    scanf("%d", &n);
    if (n < 4) {
        puts("NO");
        return 0;
    }
    puts("YES");
    fto(i, 1, (n-4)/4) {
        printf("%d - %d = 1\n", n%4+i*4+4, n%4+i*4+3);
        printf("%d - %d = -1\n", n%4+i*4+1, n%4+i*4+2);
        puts("-1 + 1 = 0");
        if (i > 1) puts("0 + 0 = 0");
    }
    if (n%4 == 0) {
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
    }
    else if (n%4 == 1) {
        puts("4 * 5 = 20");
        puts("20 + 2 = 22");
        puts("22 + 3 = 25");
        puts("25 - 1 = 24");
    }
    else if (n%4 == 2) {
        puts("4 * 5 = 20");
        puts("20 + 6 = 26");
        puts("26 + 2 = 28");
        puts("28 - 3 = 25");
        puts("25 - 1 = 24");
    }
    else {
        puts("5 * 7 = 35");
        puts("35 - 6 = 29");
        puts("29 - 4 = 25");
        puts("25 - 3 = 22");
        puts("22 + 2 = 24");
        puts("24 * 1 = 24");
    }

    if (n > 7) puts("0 + 24 = 24");

    return 0;
}