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
#define maxN 1000000

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, nt[maxN+1], a[maxN+1], tmp[maxN+1], cnta[maxN+1], cntb[maxN+1];
vector<int> v;

void Task(int x, int cnt[]) {
    while (x > 1) {
        int y = nt[x];
        if (tmp[y] == 0) v.pb(y);
        ++tmp[y];
        x /= y;
    }
    forit(it, v) {
        int x = *it;
        cnt[x] = max(cnt[x], tmp[x]);
        tmp[x] = 0;
    }
    v.clear();
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 1, maxN) nt[i] = i;
    fto(i, 2, 1000) {
        if (nt[i] == i) {
            ftoa(j, i*i, maxN, i) nt[j] = min(nt[j], i);
        }
    }

    scanf("%d%d", &n, &k);
    Task(k, cnta);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        Task(a[i], cntb);
    }

    fto(i, 2, maxN) {
        if (cnta[i] > cntb[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}