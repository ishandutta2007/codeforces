#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)

struct st
{
    int kr, cost;
};

int ans = -INF, mx1 = 0, mx2 = 0, n, a, b, cost, kr, max1[MAXN], max2[MAXN], j;
char ch;
vector<st> Vec1, Vec2;
st p;

bool cmp(st a, st b)
{
    if (a.cost != b.cost) return a.cost < b.cost;
    else return a.kr > b.kr;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> a >> b;
    forn(i, n)
    {
        cin >> kr >> cost >> ch;
        if (ch  == 'C')
        {
            if (cost <= a)
            {
                p.cost = cost;
                p.kr = kr;
                Vec1.pb(p);
                mx1 = max(mx1, kr);
            }


        }
        else if (cost <= b)
        {
            p.cost = cost;
            p.kr = kr;
            Vec2.pb(p);
            mx2 = max(mx2, kr);
        }
    }

    sort(Vec1.begin(), Vec1.end(), cmp);
    sort(Vec2.begin(), Vec2.end(), cmp);
    if (!Vec1.empty()) max1[0] = Vec1[0].kr;
    if (!Vec2.empty()) max2[0] = Vec2[0].kr;
    //cout << Vec1.size() << " " << Vec2.size() << endl;
    for(int i = 1; i < Vec1.size(); i++)
    {
        max1[i] = max(max1[i - 1], Vec1[i].kr);
    }
    for(int i = 1; i < Vec2.size(); i++)
    {
        max2[i] = max(max2[i - 1], Vec2[i].kr);
    }
    j = 0;
    for(int i = Vec1.size() - 1; i > 0; i--)
    {
        if (Vec1[i].cost + Vec1[0].cost > a) continue;
        while (j < i && a >= Vec1[i].cost + Vec1[j].cost) j++;
        ans = max(ans, Vec1[i].kr + max1[min(i - 1, j - 1)]);
    }

    j = 0;
    //cout << max2[0] << endl;
    for(int i = Vec2.size() - 1; i > 0; i--)
    {
        if (Vec2[i].cost + Vec2[0].cost > b) continue;
        while (j < i && b >= Vec2[i].cost + Vec2[j].cost) j++;
        //cout << Vec2[i].cost << " " << Vec2[j].cost << " " << b << endl;
        //cout << i << " " << j << endl;
        ans = max(ans, Vec2[i].kr + max2[min(i - 1, j - 1)]);
    }

    if (Vec1.size() > 0 && Vec2.size() > 0) ans = max(ans, mx1 + mx2);
    if (ans > -INF) cout << ans;
    else cout << 0;








    return 0;
}