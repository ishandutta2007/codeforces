#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define debug(x) cout << #x << " == " << (x) << '\n';

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class SegTree
{
private:
    vector<int> st;
    const vector<int>& A;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1; }

    int mid(int L, int R) { return (L + R) / 2; }

    void build(int p, int L, int R, int i, int j)
    {
        if (R < i || j < L)
            return;

        if (L == R)
            st[p] = single(L);

        else
        {
            build(left(p), L, mid(L, R), i, j);
            build(right(p), mid(L, R) + 1, R, i, j);

            int r1 = st[left(p)], r2 = st[right(p)];

            st[p] = op(r1, r2);
        }
    }

    int range_query(int p, int L, int R, int i, int j)
    {
        if (R < i || j < L)
            return -1;

        if (i <= L && R <= j)
            return st[p];

        int r1 = range_query(left(p), L, mid(L, R), i, j);
        int r2 = range_query(right(p), mid(L, R) + 1, R, i, j);

        if (j <= mid(L, R))
            return r1;

        if (mid(L, R) < i)
            return r2;

        return op(r1, r2);
    }
public:
    SegTree(const vector<int>& _A) : A(_A)
    {
        n = A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1, 0, n - 1);
    }
    int range_query(int i, int j)
    {
        return range_query(1, 0, n - 1, i, j);
    }
    void update(int i, int j = -1)
    {
        if (j == -1)
            j = i;

        build(1, 0, n - 1, i, j);
    }
    int op(int r1, int r2)
    {
        return A[r1] >= A[r2] ? r1 : r2;
    }
    int single(int i)
    {
        return i;
    }
};

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vi a(n);
        int a_max = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a_max = max(a[i], a_max);
        }

        SegTree A(a);

        int m; cin >> m;
        map<int, int> H;
        int p_max = -1;
        for (int j = 0; j < m; ++j)
        {
            int p, s; cin >> p >> s;
            H[p] = max(H[p], s);
            p_max = max(p, p_max);
        }

        if (p_max < a_max)
        {
            cout << -1 << endl;
            continue;
        }

        vi p, s;
        for (auto [k, v] : H)
        {
            p.pb(k);
            s.pb(v);
        }
        SegTree S(s);

        int days = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = i;
            int r = n;
            while (l < r - 1)
            {
                int mid = (l + r) / 2;
                auto iter = lower_bound(p.begin(), p.end(), a[A.range_query(i, mid)]);
                int hlow = distance(p.begin(), iter);

                if (s[S.range_query(hlow, m - 1)] >= mid - i + 1)
                    l = mid;
                else
                    r = mid;
            }

            i = l;
            days++;
        }

        cout << days << endl;
    }
    exit(0);
}