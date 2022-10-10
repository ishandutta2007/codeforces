#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<pair<pair<int,char>,pair<int,int> > > v;

struct segment_change
{
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    void reset()
    {
        to_add = 0;
    }

    bool has_change() const
    {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const
    {
        return segment_change(to_add + other.to_add);
    }
};

struct segment
{
    int maximum;

    segment(int _maximum = numeric_limits<int>::min()) : maximum(_maximum) {}

    void apply(int, const segment_change &change)
    {
        maximum += change.to_add;
    }

    void join(const segment &other)
    {
        maximum = max(maximum, other.maximum);
    }

    void join(const segment &a, const segment &b)
    {
        *this = a;
        join(b);
    }
};

struct seg_tree
{
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = 0)
    {
        if (n > 0)
            init(n);
    }

    void init(int n)
    {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial)
    {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length)
    {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n)
        {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op)
    {
        if (a <= start && end <= b)
        {
            range_op(position, end - start);
            return;
        }

        if (position >= tree_n)
            return;

        push_down(position, end - start);
        int mid = (start + end) / 2;
        if (a < mid)
            process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid)
            process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b)
    {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int)
        {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change)
    {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(1, 0, tree_n, a, b, true, [&](int position, int length)
        {
            tree[position].apply(length, change);
            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};

const int MAX=4000007;

inline int f(int a)
{
    if (a<0)
        a=0;
    if (a>MAX)
        a=MAX;
    return a;
}

seg_tree tree(MAX);

int main()
{
    tree.build(vector<segment>(MAX, segment(0)));

    int n,r;
    cin >> n >> r;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        int X=a+b+2000000;
        int Y=a-b+2000000;

        v.push_back({{X-r,-1},{f(Y-r),f(Y+r)}});
        v.push_back({{X+r,1},{f(Y-r),f(Y+r)}});
    }
    sort(v.begin(),v.end());
    int ans=0;
    for (auto &s:v)
    {
        //cout << s.first.first-2000000 << ' ' << s.second.first-2000000 << ' ' << s.second.second-2000000 << ' ' << int(s.first.second) << endl;
        tree.update(s.second.first,s.second.second+1,segment_change(-s.first.second));
        ans=max(ans,tree.query(0,MAX).maximum);
        //cout << tree.query(0,MAX).maximum << endl;
    }
    cout << ans;
    return 0;
}