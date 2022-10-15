#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class SegTreeLazy
{
private:
    vector<int> st;
    const vector<int> A;
    vector<int> lazy;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1; }

    int mid(int L, int R) { return (L + R) >> 1; }

    void build(int p, int L, int R, int i, int j)
    {
        if (R < i || j < L)
            return;

        if (L == R)
            st[p] = A[L];

        else
        {
            build(left(p), L, mid(L, R), i, j);
            build(right(p), mid(L, R) + 1, R, i, j);

            int r1 = st[left(p)], r2 = st[right(p)];

            st[p] = max(r1, r2);
        }
    }

    void push(int p, int L, int R)
    {
        if (lazy[p] != 0)
        {
            st[p] += lazy[p];

            if (L < R)
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, int diff)
    {
        push(p, L, R);

        if (R < i || j < L)
            return;

        if (i <= L && R <= j)
        {
            st[p] += diff;

            if (L < R)
            {
                lazy[left(p)] += diff;
                lazy[right(p)] += diff;
            }
            return;
        }

        update(left(p), L, mid(L, R), i, j, diff);
        update(right(p), mid(L, R) + 1, R, i, j, diff);

        st[p] = max(st[left(p)], st[right(p)]);
    }

    int range_query(int p, int L, int R, int i, int j)
    {
        push(p, L, R);

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

        return max(r1, r2);
    }
public:
    SegTreeLazy(const vector<int>& _A) : A(_A)
    {
        n = A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, 0, n - 1);
    }
    int range_query(int i, int j)
    {
        return range_query(1, 0, n - 1, i, j);
    }
    void update(int i, int j, int diff)
    {
        update(1, 0, n - 1, i, j, diff);
    }
};

int main()
{ _
    int n, k; cin >> n >> k;

    vi a(1e5 + 10, 0);
    SegTreeLazy T(a);

    vvi L(n, vi(3));
    for (int i = 0; i < n; ++i)
    {
        cin >> L[i][0] >> L[i][1];
        L[i][0]--;
        L[i][1]--;
        L[i][2] = i + 1;
        T.update(L[i][0], L[i][1], 1);
    }
    sort(L.begin(), L.end());

    int c = 0;
    vi vis(n, 0);
    priority_queue<vi, vvi> pq;

    vi q;
    for (int i = 0; i < n; ++i)
    {
        int x = L[i][0];
        do
        {
            pq.push({L[i][1], L[i][0], L[i][2]});
            i++;
        } while(i < n && L[i][0] == x);
        i--;


        while (T.range_query(x, x) > k)
        {
            c++;
            int a = pq.top()[1], b = pq.top()[0];
            q.pb(pq.top()[2]);
            T.update(a, b, -1);
            pq.pop();
        }
    }
    cout << c << endl;
    for (auto x : q)
        cout << x << " ";
    cout << endl;

    exit(0);
}