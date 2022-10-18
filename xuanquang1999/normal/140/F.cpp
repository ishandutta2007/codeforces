#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

struct pt {
    int x, y;
    bool operator < (const pt &p) const {return make_tuple(x, y) < make_tuple(p.x, p.y);}
    bool operator == (const pt &p) const {return x == p.x && y == p.y;};
    pt operator + (pt p) {return {x + p.x, y + p.y};}
};

const int MAXN = 200005;

int n, k;
pt p[MAXN];
set<pt> ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n-1)
        scanf("%d%d", &p[i].x, &p[i].y);

    if (k >= n) {
        puts("-1");
        return 0;
    }

    sort(p, p+n);

    fto(l, 0, min(n-1, k)) {
        fdto(r, n-1, max(n-1-k, l)) {
            int cntSkip = l + n-1-r;
            if (cntSkip > k)
                continue;
//            printf("%d %d %d\n", l, r, cntSkip);

            pt center = p[l] + p[r];
            int j = r;
            for(int i = l; i <= j; ++i) {
                while (i < j && center < p[i] + p[j]) {
                    ++cntSkip;
                    --j;
                }
                if (p[i] + p[j] == center)
                    --j;
                else
                    ++cntSkip;
            }

            if (cntSkip <= k)
                ans.insert(center);
        }
    }

    printf("%d\n", sz(ans));
    for(pt p: ans)
        printf("%.15g %.15g\n", p.x/2.0, p.y/2.0);


    return 0;
}