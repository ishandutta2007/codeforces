#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

template<typename T>
struct F1
{
    int L, R;
    T add;

    F1(T add) : add(add) {}

    T apply_aggregate(const T& old) const
    {
        return old + add;
    }
    void compose(const F1<T>& op)
    {
        add += op.add;
    }
    void operator=(const F1& op)
    {
        add = op.add;
    }
};

template<typename T, typename F>
class SegmentTree
{
private:
    const int n;
    vector<T> st;
    const T T_id;
    const F F_id;
    vector<F> d;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    T combine(const T& left, const T& right)
    {
        return max(left, right);
    }
    T value(int p)
    {
        return st[p];
    }

    void init(int p, int L, int R)
    {
        d[p].L = L;
        d[p].R = R;

        d[p] = F_id;
    }

    void build(const vector<T>& source, int p, int l, int r)
    {
        if (l > r)
            return;

        init(p, l, r);
        if (l == r)
            st[p] = source[l];
        else
        {
            int m = (l + r) / 2;
            build(source, left(p), l, m);
            build(source, right(p), m + 1, r);
            st[p] = combine(value(left(p)), value(right(p)));
        }
    }
    void push(int p, int l, int r)
    {
        if (l < r)
        {
            d[left(p)].compose(d[p]);
            d[right(p)].compose(d[p]);
        }
        st[p] = d[p].apply_aggregate(value(p));
        d[p] = F_id;
    }
    void update(int p, int l, int r, int L, int R, F op)
    {
        push(p, l, r);

        if (R < l || r < L || r < l)
            return;

        if (L <= l && r <= R)
        {
            d[p].compose(op);
            push(p, l, r);
        }
        else
        {
            push(p, l, r);
            int m = (l + r) / 2;
            update(left(p),     l,      m, L, R, op);
            update(right(p),    m + 1,  r, L, R, op);
            st[p] = combine(value(left(p)), value(right(p)));
        }
    }
    T query(int p, int l, int r, int L, int R)
    {
        push(p, l, r);

        if (r < L || R < l || r < l)
            return T_id; // this should not matter

        if (L <= l && r <= R)
            return value(p);

        int m = (l + r) / 2;

        T q1 = query(left(p), l, m, L, R);
        T q2 = query(right(p), m + 1, r, L, R);

        if (R <= m)
            return q1;
        else if (m < L)
            return q2;
        else
            return combine(q1, q2);
    }
public:
    SegmentTree(vector<T>& source, T id) : n(source.size()), T_id(id), F_id(F(id))
    {
        st.assign(4 * n, id);
        d.assign(4 * n, F_id);
        build(source, 1, 0, n - 1);
    }
    T query(int L, int R)
    {
        return query(1, 0, n - 1, L, R);
    }
    void update(int L, int R, F op)
    {
        update(1, 0, n - 1, L, R, op);
    }
};

int main()
{
    int n, k; cin >> n >> k;

    vi a(2 * 1e5 + 10, 0);
    SegmentTree<int, F1<int>> T(a, 0);

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


        while (T.query(x, x) > k)
        {
            c++;
            int a = pq.top()[1], b = pq.top()[0];
            q.push_back(pq.top()[2]);
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