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

char tmp[maxN];
void read(string &s) {
    scanf("%s", tmp);
    s.assign(tmp);
}

struct BIT {
private: vector<int> t;
public:
    BIT() {}
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        ++p;
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        ++p;
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
    int query(int l, int r) {
        return query(r)-query(l-1);
    }
};

string s;
int n, Q, m[256];
BIT t[4][10][10];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    read(s); n = s.length();
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;

    fto(i, 0, 3) fto(e, 1, 10) fto(r, 0, e-1) t[i][e-1][r] = BIT(n);

    fto(e, 1, 10) {
        fto(i, 0, n-1) t[m[s[i]]][e-1][i%e].update(i, 1);
    }

    scanf("%d", &Q);
    fto(i, 1, Q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int p; char c[2]; scanf("%d%s", &p, c); --p;
            fto(e, 1, 10) {
                t[m[s[p]]][e-1][p%e].update(p, -1);
                t[m[c[0]]][e-1][p%e].update(p, 1);
            }
            s[p] = c[0];
        } else {
            int l, r; string s;
            scanf("%d%d", &l, &r); read(s); --l; --r;
            int ans = 0;
            fto(i, 0, sz(s)-1) {
                ans += t[m[s[i]]][sz(s)-1][(l+i)%sz(s)].query(l, r);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}