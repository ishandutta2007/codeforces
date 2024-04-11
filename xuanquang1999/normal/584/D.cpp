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
#define oo 1000000007
#define EPS 10e-9

bool isPrime(int n) {
    if (n < 2) return false;
    int k = (int)sqrt(n);
    fto(i, 2, k) {
        if (n%i == 0) return false;
    }
    return true;
}

int n, p1;

int main() {
    scanf("%d", &n);
    if (n == 3) printf("1\n3");
    else if (n == 4) printf("2\n2 2");
    else if (n == 5) printf("2\n2 3");
    else {
        int p1 = n-4;
        while (!isPrime(p1)) --p1;
        int p2 = n-p1-2, p3 = n-p1-p2;
        while (!isPrime(p2) || !isPrime(p3)) --p2, ++p3;
        puts("3");
        printf("%d %d %d", p1, p2, p3);
    }

    return 0;
}