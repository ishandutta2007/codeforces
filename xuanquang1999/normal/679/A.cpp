//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

bool isPrime(int x) {
    fto(i, 2, (int)sqrt(x)) {
        if (x%i == 0) return false;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(x, 2, 7) {
        if (isPrime(x)) {
            printf("%d\n", x*x);
            fflush(stdout);

            char s[10];
            scanf("%s", s);
            if (s[0] == 'y') {
                puts("composite");
                fflush(stdout);
                return 0;
            }
        }
    }

    int cnt = 0;
    fto(x, 2, 50) {
        if (isPrime(x)) {
            printf("%d\n", x);
            fflush(stdout);

            char s[10];
            scanf("%s", s);
            if (s[0] == 'y') ++cnt;
        }
    }

    if (cnt >= 2) {
        puts("composite");
        fflush(stdout);
        return 0;
    }

    puts("prime");
    fflush(stdout);

    return 0;
}