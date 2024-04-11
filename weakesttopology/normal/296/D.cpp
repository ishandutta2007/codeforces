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
    int A[500][500] = { { INF } };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vi x(n); READ(x);
    for (int i = 0; i < n; ++i)
        x[i]--;

    int B[500][500];
    memset(B, INF, sizeof B);

    vll S(n, 0);
    for (int k = n - 1; k >= 0; --k)
    {
        for (int i = k; i < n; ++i)
        {
            B[x[i]][x[k]] = A[x[i]][x[k]];
            B[x[k]][x[i]] = A[x[k]][x[i]];
        }

        vi dist(n, INF); dist[x[k]] = 0;
        priority_queue<ii, vii, greater<ii>> pq; pq.push(mp(0, x[k]));

        while (!pq.empty())
        {
            ii front = pq.top(); pq.pop();
            int d = front.f, u = front.s;

            if (d > dist[u])
                continue;

            for (int v = 0; v < n; ++v)
            {
                int w = B[u][v];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push(mp(dist[v], v));
                }
            }
        }
        for (int i = 0; i < n; ++i)
            B[x[k]][i] = dist[i];

        dist.assign(n, INF); dist[x[k]] = 0;
        pq.push(mp(0, x[k]));

        while (!pq.empty())
        {
            ii front = pq.top(); pq.pop();
            int d = front.f, u = front.s;

            if (d > dist[u])
                continue;

            for (int v = 0; v < n; ++v)
            {
                int w = B[v][u];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push(mp(dist[v], v));
                }
            }
        }
        for (int i = 0; i < n; ++i)
            B[i][x[k]] = dist[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                B[i][j] = min(B[i][j], B[i][x[k]] + B[x[k]][j]);

        for (int i = k; i < n; ++i)
            for (int j = k; j < n; ++j)
                S[k] += B[x[i]][x[j]];
    }

    for (auto s : S)
        cout << s << " ";
    cout << endl;

    exit(0);
}