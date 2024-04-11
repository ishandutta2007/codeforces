using namespace std;
#include <bits/stdc++.h>
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
#define maxM 1000005

ll m, a1, a2, h1, h2, x1, x2, y2;
ll d1[2*maxM], d2[2*maxM], lcnt1, lcnt2, rcnt1, rcnt2, cnt1, cnt2;
ll visited[maxM];

void CalcD(ll h, ll x, ll y, ll d[], ll &lcnt, ll &rcnt) {
    rcnt = 1;
    memset(visited, 0, sizeof(visited));
    while (!visited[h]) {
        visited[h] = rcnt;
        d[rcnt] = h; ++rcnt;
        h = (x*h + y)%m;
    }

    lcnt = visited[h];
    fto(i, rcnt, 2*maxM-1) {
        d[i] = h;
        h = (x*h + y)%m;
    }
    --rcnt;
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ll y1;
    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;

    CalcD(h1, x1, y1, d1, lcnt1, rcnt1);
    CalcD(h2, x2, y2, d2, lcnt2, rcnt2);

    if (lcnt1 < lcnt2) {
        rcnt1+=lcnt2-lcnt1;
        lcnt1 = lcnt2;
    }
    else {
        rcnt2+=lcnt1-lcnt2;
        lcnt2 = lcnt1;
    }

    fto(i, 1, lcnt1-1)
        if (d1[i] == a1 && d2[i] == a2) {
            printf("%d", i-1);
            return 0;
        }

    ll i1 = 0, i2 = 0;
    fto(i, lcnt1, rcnt1)
        if (d1[i] == a1) {
            i1 = i;
            break;
        }
    fto(i, lcnt2, rcnt2)
        if (d2[i] == a2) {
            i2 = i;
            break;
        }

    if (i1 == 0 || i2 == 0) {
        printf("-1");
        return 0;
    }

    cnt1 = rcnt1-lcnt1+1; cnt2 = rcnt2-lcnt2+1;
    ll bcnn = cnt1/__gcd(cnt1, cnt2) * cnt2;
    ll k1 = 0, k2 = 0;
    while (cnt1) {
        if (i1 < i2) {
            i1+=cnt1;
            ++k1;
        }
        else if (i1 > i2) {
            i2+=cnt2;
            ++k2;
        }
        else {
            printf("%I64d", i1-1);
            return 0;
        }
        if (k1 > bcnn/cnt1 && k2 > bcnn/cnt2) break;
    }

    printf("-1");
    return 0;
}