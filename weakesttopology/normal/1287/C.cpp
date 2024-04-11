#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size();

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n; cin >> n;

    set<int> P;
    vi p(n); READ(p);

    int last = -1;
    priority_queue<ii, vii, greater<ii>> pq;
    for (int i = 0; i < n; ++i)
    {
        if (not p[i])
            continue;

        P.insert(p[i]);
        if (last != -1 && (p[i] + p[last]) % 2 == 0)
            pq.push({ i - last, last });

        last = i;
    }

    if ((int)P.size() == 0)
    {
        cout << (n > 1) << endl;
        exit(0);
    }

    set<int> D[2] = { set<int>() };
    for (int i = 1; i <= n; ++i)
        if (P.count(i) == 0)
            D[i % 2].insert(i);

    while (not pq.empty())
    {
        ii z = pq.top(); pq.pop();

        int s = z.s, e = z.s + z.f;
        int b = p[s] % 2;

        if (e - s - 1 > (int)D[b].size())
            break;

        for (int i = s + 1; i < e; ++i)
        {
            if (D[b].empty())
                b = !b;
            p[i] = *D[b].begin();
            D[b].erase(D[b].begin());
        }
    }

    pq = decltype(pq)();

    if (p[0] == 0)
    {
        int i = 0;
        while (p[i] == 0)
            ++i;
        pq.push({ i + 1, - 1});
    }
    if (last < n - 1)
        pq.push({ n - last, last });

    while (not pq.empty())
    {
        ii z = pq.top(); pq.pop();

        int s = z.s, e = z.s + z.f;
        int b = s == -1 ? p[e] % 2 : p[s] % 2;

        if (s == -1)
        {
            int t = max(e - (int)D[b].size(), 0);
            for (int i = 0; i < t; ++i)
            {
                p[i] = *D[!b].begin();
                D[!b].erase(D[!b].begin());
            }
            for (int i = t; i < e; ++i)
            {
                p[i] = *D[b].begin();
                D[b].erase(D[b].begin());
            }
        }
        else
        {
            for (int i = s + 1; i < e; ++i)
            {
                if (D[b].empty())
                    b = !b;
                p[i] = *D[b].begin();
                D[b].erase(D[b].begin());
            }
        }
    }


    for (int i = 1; i < n; ++i)
    {
        int b = p[i - 1] % 2;

        while (i < n && p[i] == 0)
        {
            if (D[b].empty())
                b = !b;

            p[i] = *D[b].begin();
            D[b].erase(D[b].begin());
            ++i;
        }
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i)
        ans += (p[i] + p[i + 1]) % 2;

    // for (auto x : p)
    //     cerr << x << " ";
    // cerr << endl;

    cout << ans << endl;

    exit(0);
}