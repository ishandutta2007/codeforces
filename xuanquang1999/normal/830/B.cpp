//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
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

struct BIT {
private: vector<int> t;
public:
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
    int query(int l, int r) {
        return query(r)-query(l-1);
    }
};

int n, a[maxN];
set<int> num, pos[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        num.insert(a[i]);
        pos[a[i]].insert(i);
    }

    BIT t(n);
    fto(i, 1, n) t.update(i, 1);
    int i = 1;
    ll ans = 0;
    for(int x: num) {
        while (!pos[x].empty()) {
            set<int>::iterator it;
            it = pos[x].lower_bound(i);
            int j;
            if (it == pos[x].end()) {
                it = pos[x].begin();
                j = *it;
                ans += t.query(i, n)+t.query(1, j);
//                printf("%d\n", t.query(i, n)+t.query(1, j));
            } else {
                j = *it;
                ans += t.query(i, j);
//                printf("%d\n", t.query(i, j));
            }
//            printf("%d %d\n", x, j);
            pos[x].erase(it);
            t.update(j, -1);
            i = j;
        }
    }

    cout << ans;

    return 0;
}