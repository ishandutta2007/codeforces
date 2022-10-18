using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 131072

int k, q, n, t[2*maxN];

void build() {
    int m, op;
    for(m = n-1, op = 0; m > 0; m>>=1, op^=1)
        for(int i = m; i > m>>1; --i)
            t[i] = (op == 0) ? t[i<<1] | t[i<<1|1] : t[i<<1] ^ t[i<<1|1];
}

void update(int p, int x) {
    int op;
    for (op = 0, t[p+=n] = x; p > 1; p>>=1, op^=1)
        t[p>>1] = (op == 0) ? t[p] | t[p^1] : t[p] ^ t[p^1];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &k, &q);
    n = 1;
    fto(i, 1, k) n<<=1;

    fto(i, 0, n-1) scanf("%d", t+n+i);

    build();
//    fto(i, 1, 2*n-1) printf("%d ", t[i]);
//    printf("\n");

    fto(i, 1, q) {
        int p, b;
        scanf("%d%d", &p, &b);
        update(p-1, b);
        printf("%d\n", t[1]);

//        fto(i, 1, 2*n-1) printf("%d ", t[i]);
//        printf("\n");
    }

    return 0;
}