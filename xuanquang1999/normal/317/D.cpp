//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 200005
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int g[29] = {1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int cnt[29], n;
set<int> s;

//map<int, int> m;
//
//int Solve(int x) {
//    if (m.find(x) != m.end()) return m[x];
//    unordered_set<int> s;
//    fto(i, 0, 28) {
//        if ((x>>i)&1) {
//            int y = x;
//            for(int j = i; j <= 28; j += i+1) y &= ~(1<<j);
//            //printf("%d %d\n", x, y);
//            s.insert(Solve(y));
//        }
//    }
//    fto(i, 0, 29) {
//        if (s.find(i) == s.end()) return m[x] = i;
//    }
//}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    fto(i, 1, 29) {
//        g[i] = Solve((1<<i)-1);
//    }

//    fto(i, 1, 29) printf("%d ", g[i]);

    scanf("%d", &n);

    fto(i, 2, sqrt(n)) {
        if (s.find(i) == s.end()) {
            int p = 0;
            for(ll j = i; j <= n; j *= i) {
                ++p;
                s.insert(j);
            }
            ++cnt[p-1];
//            printf("%d %d\n", i, p);
        }
    }
    cnt[0] = n-sz(s);

//    fto(i, 0, 28) printf("%d ", cnt[i]);

    int ans = 0;
    fto(i, 0, 28) ans ^= (cnt[i]&1)*g[i];
    puts((ans) ? "Vasya" : "Petya");

    return 0;
}