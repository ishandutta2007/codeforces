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
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define maxX 2000005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

bool nt[maxX];
int n, a[maxN], maxA, cnt1;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        maxA = max(maxA, a[i]);
        if (a[i] == 1) ++cnt1;
    }
    maxA *= 2;
    memset(nt, true, sizeof nt);

    fto(i, 2, (int)sqrt(maxA)) {
        if (nt[i]) {
            ftoa(j, i*i, maxA, i) nt[j] = false;
        }
    }

    if (cnt1 >= 2) {
        fto(i, 1, n) {
            if (a[i] != 1 && nt[a[i]+1]) {
                printf("%d\n", cnt1+1);
                printf("%d", a[i]);
                fto(i, 1, cnt1) printf(" %d", 1);
                return 0;
            }
        }
        printf("%d\n", cnt1);
        fto(i, 1, cnt1) printf(" %d", 1);
        return 0;
    }

    fto(i, 1, n) {
        fto(j, i+1, n) {
            if (nt[a[i]+a[j]]) {
                printf("2\n%d %d", a[i], a[j]);
                return 0;
            }
        }
    }

    printf("1\n%d", a[1]);

    return 0;
}