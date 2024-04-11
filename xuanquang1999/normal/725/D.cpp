//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 300005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct team {
    ll t, w;
    int id;
};

bool cmpB(team a, team b) {
    return (a.w-a.t < b.w-b.t);
}

bool cmpT(team a, team b) {
    return (a.t > b.t);
}

int LSOne(int x) {
    return x & (-x);
}

class FenwickTree {
private: vector<ll> t;
    ll _query(int p) {
        ll res = 0;
        for(; p > 0; p -= LSOne(p)) res += t[p];
        return res;
    }
    ll _query(int l, int r) {
        return query(r) - ((l == 1) ? 0 : query(l-1));
    }
    void _update(int p, ll x) {
        for(; p < t.size(); p += LSOne(p)) t[p] += x;
    }
public:
    FenwickTree(int n) {t.resize(n+1, 0);}
    ll query(int p) {
        return _query(p);
    }
    void update(int l, int r, ll x) {
        _update(r+1, -x);
        _update(l, x);
    }
};

int n;
team a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%I64d%I64d", &a[i].t, &a[i].w);
    }

    sort(a+2, a+n+1, cmpB);
    fto(i, 2, n) a[i].id = i-1;
    sort(a+2, a+n+1, cmpT);

    FenwickTree tD(n+1), tCnt(n+1);
    int l = 1, cnt = n-1, ans = 1;
    fto(i, 2, n) {
        if (a[i].t > a[1].t) ++ans;
    }
    fto(r, 2, n+1) {
        while (a[l+1].t > a[r].t) {
            ++l;
            tD.update(a[l].id, cnt, a[l].w-a[l].t+1);
            tCnt.update(a[l].id, cnt, 1);
            while (tD.query(cnt) > a[1].t) --cnt;
        }
        if (a[1].t > a[r].t) {
            int lo = 1, hi = cnt, res = 0;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (tD.query(mid) <= a[1].t-a[r].t) {
                    res = max(res, mid);
                    lo = mid+1;
                }
                else hi = mid-1;
            }
            int cnt = ((res != 0) ? tCnt.query(res) : 0);
            ans = min(ans, l-cnt);
        }
    }

    cout << ans;



    return 0;
}