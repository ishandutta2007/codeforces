#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

struct tprob
{
    int p, t;
    ll endt, startt;
};

inline bool operator<(const tprob &a, const tprob &b)
{
    return (ll)a.p * b.t > (ll)b.p * a.t;
}

inline bool cmpp(const tprob &a, const tprob &b)
{
    return a.p < b.p;
}

const int maxn = 150005;

tprob a[maxn];
vector<int> now;
int n;
ll T;

bool can(ld c)
{
    ld rb = 0;
    ld newrb = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && a[i].p != a[i - 1].p)
        {
            rb = newrb;
        }
        if (a[i].p * (1 - c * a[i].endt / T) < rb) return false;
        newrb = max(newrb, a[i].p * (1 - c * a[i].startt / T));
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].p);
    T = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].t);
        T += a[i].t;
    }
    sort(a, a + n);
//     for (int i = 0; i < n; i++) cout << a[i].p << ' ' << a[i].t << ' ' << a[i].startt << ' ' << a[i].endt << endl;
    ll curt = 0;
    ll sumt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && a[i].p * a[i - 1].t != a[i].t * a[i - 1].p)
        {
            curt = sumt;
            for (auto t : now)
            {
                a[t].endt = curt;
            }
            now.clear();
        }
        a[i].startt = curt + a[i].t;
        now.push_back(i);
        sumt += a[i].t;
    }
    curt = sumt;
    for (auto t : now)
    {
        a[t].endt = curt;
    }
    now.clear();
    sort(a, a + n, cmpp);
//     for (int i = 0; i < n; i++) cout << a[i].p << ' ' << a[i].t << ' ' << a[i].startt << ' ' << a[i].endt << endl;
    ld l = 0;
    ld r = 1;
    for (int IT = 0; IT < 70; IT++)
    {
        ld m = (l + r) / 2;
        if (can(m)) l = m;
        else r = m;
    }
    printf("%.20f\n", (double)l);
    return 0;
}