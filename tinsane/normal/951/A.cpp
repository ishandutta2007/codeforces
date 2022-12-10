#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x_) cerr << #x_ << " : " << x_ << endl
#define dbga(arr_, len_) {cerr << #arr_ << " : "; for (int _ = 0; _ < len_; _++) cerr << arr_[_] << " "; cerr << endl;}
#define dbgi(it_) {cerr << #it_ << " : "; for (const auto& _ : it_) cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr_, len_) (void)0
#define dbgi(it_) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = 100500;

int n;
char s[N];

void solve()  {
    scanf("%s", s);
    n = strlen(s);

    int best = 0;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] != s[i - 1])
            cur++;
        else
            cur = 1;
        best = max(best, cur);
    }

    if (s[0] != s[n - 1]) {
        int ptr1 = 1;
        while (ptr1 < n && s[ptr1] != s[ptr1 - 1])
            ptr1++;
        int ptr2 = n - 2;
        while (ptr2 >= 0 && s[ptr2] != s[ptr2 + 1])
            ptr2--;
        cur = ptr1 + (n - 1 - ptr2);
        cur = min(cur, n);
        best = max(best, cur);
    }

    printf("%d\n", best);
}

int main()  {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}