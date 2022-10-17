//EZ VK CUP(NET)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF=1e9 + 1;
ll const BINF=1e18 + 1;
int const MAXN = 1e6  + 10;
double const eps = 0.0000001;

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

struct graph
{
    int from,to,cost;
};

struct coor
{
    int x,y;
};

/*void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < Vec[v].size(); i++)
    {
        if (!used[Vec[v][i]])
        {
            dfs(Vec[v][i]);
        }
    }
}*/

vector<pair<ld, ld> > Vec;
ld min1 = 1e18, x, x2, y, y2, a, b, c, mx, my, k, d;

pair<ld, ld> p;
int n, j, j2;
bool t, t1;
set<int> st;
map<int,int> mp;
queue<int> q;
string s, s1, s2;
stringstream str;
char ch, ch1, ch2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> p.f >> p.sec;
        Vec.pb(p);
    }

    fore(i, n)
    {
        if (i > 0) j = i - 1;
        else j = n - 1;
        if (i < n - 1) j2 = i + 1;
        else j2 = 0;
        x = Vec[j].f;
        y = Vec[j].sec;
        x2 = Vec[j2].f;
        y2 = Vec[j2].sec;
        a = y - y2;
        b = x2 - x;
        c = -a * x - b * y;
        mx = Vec[i].f;
        my = Vec[i].sec;
        k = a * mx + b * my + c;
        if (k < 0) k *= (-1);
        d = k / (sqrt(a * a + b * b));
        min1 = min(min1, d);
    }

    cout << fixed << setprecision(8) << min1 / 2;



    return 0;
}