//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define maxR 10005
#define double long double

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct cake {
    //double r, h;
    ll v;
    int id;
    inline bool operator < (const cake &b) const{
        return (v < b.v || (v == b.v && id > b.id));
    }
};

const double PI = acos(-1.0);

int n;
cake c[maxN];
ll t[2*maxN];

void update(int p, ll x) {
    if (t[p+=n-1] > x) return;
    for(t[p] = x; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

ll query(int l, int r) {
    ll res = 0;
    for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int r, h;
        scanf("%d%d", &r, &h);
        c[i].v = (ll)r*r*h;
        c[i].id = i;
    }
    sort(c+1, c+n+1);

    fto(i, 1, n) {
        update(c[i].id, query(1, c[i].id-1)+c[i].v);
//        fto(j, 1, mr*2-1) cout << t[j] << " ";
//        cout << endl;
    }

    cout << setprecision(69) << PI*t[1];

    return 0;
}