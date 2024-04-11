#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

struct tsob
{
    int x;
    int id;
};

inline bool operator<(const tsob &a, const tsob &b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.id < b.id;
}

const int maxn = 200005;
const int treesize = 1 << 20;
const int inf = 1e9 + 9;

vector<tsob> sobs;
vector<int> xs;
int lo[maxn], ro[maxn];
int l[maxn], r[maxn], c[maxn];
pair<int, int> treein[2 * treesize], treeout[2 * treesize];
int n, m;

void set(pair<int, int> *tree, int cur, int cl, int cr, int x, pair<int, int> t)
{
    if (cl > x || cr < x) return;
    if (cl == cr)
    {
        tree[cur] = max(tree[cur], t);
        return;
    }
    int cm = (cl + cr) / 2;
    set(tree, cur * 2, cl, cm, x, t);
    set(tree, cur * 2 + 1, cm + 1, cr, x, t);
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}

pair<int, int> get(pair<int, int> *tree, int cur, int cl, int cr, int l, int r)
{
    if (cl > r || cr < l) return {-inf, -inf};
    if (cl >= l && cr <= r) return tree[cur];
    int cm = (cl + cr) / 2;
    return max(get(tree, cur * 2, cl, cm, l, r), get(tree, cur * 2 + 1, cm + 1, cr, l, r));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &lo[i], &ro[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &l[i], &r[i], &c[i]);
    }
    pair<ll, pair<int, int>> answer = {0, {-1, -1}};
    for (int _ = 0; _ < 2; _++)
    {
        xs.clear();
        for (int i = 0; i < n; i++)
        {
            xs.push_back(lo[i]);
            xs.push_back(ro[i]);
        }
        for (int i = 0; i < m; i++)
        {
            xs.push_back(l[i]);
            xs.push_back(r[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(all(xs)) - xs.begin());
        sobs.clear();
        for (int i = 0; i < n; i++)
        {
            sobs.push_back({lower_bound(all(xs), ro[i]) - xs.begin(), - i - 1});
        }
        for (int i = 0; i < m; i++)
        {
            sobs.push_back({lower_bound(all(xs), r[i]) - xs.begin(), i});
        }
        sort(all(sobs));
        for (auto s : sobs)
        {
//             cout << "new " << s.x << ' ' << s.id << endl;
            if (s.id < 0)
            {
                int id = -s.id - 1;
                int curl = lower_bound(all(xs), lo[id]) - xs.begin();
                set(treein, 1, 0, treesize - 1, curl, {ro[id] - lo[id], id});
                set(treeout, 1, 0, treesize - 1, curl, {ro[id], id});
            } else
            {
                int curl = lower_bound(all(xs), l[s.id]) - xs.begin();
                int curr = lower_bound(all(xs), r[s.id]) - xs.begin();
                auto bestin = get(treein, 1, 0, treesize - 1, curl, curr);
                auto bestout = get(treeout, 1, 0, treesize - 1, 0, curl);
//                 cout << bestout.first << ' ' << bestout.second << endl;
                bestout.first -= l[s.id];
                if ((ll)bestin.first * c[s.id] > answer.first)
                {
                    answer.first = (ll)bestin.first * c[s.id];
                    answer.second = {bestin.second, s.id};
                }
                if ((ll)bestout.first * c[s.id] > answer.first)
                {
                    answer.first = (ll)bestout.first * c[s.id];
                    answer.second = {bestout.second, s.id};
                }
            }
        }
        memset(treein, 0, sizeof treein);
        memset(treeout, 0, sizeof treeout);
        for (int i = 0; i < n; i++)
        {
            lo[i] = inf - lo[i];
            ro[i] = inf - ro[i];
            swap(lo[i], ro[i]);
        }
        for (int i = 0; i < m; i++)
        {
            l[i] = inf - l[i];
            r[i] = inf - r[i];
            swap(l[i], r[i]);
        }
    }
    sobs.clear();
    for (int i = 0; i < n; i++)
    {
        sobs.push_back({lo[i], - i - 1});
    }
    for (int i = 0; i < m; i++)
    {
        sobs.push_back({l[i], i});
    }
    sort(all(sobs));
    pair<int, int> curmax = {-1, -1};
    for (auto s : sobs)
    {
        if (s.id < 0)
        {
            int id = -s.id - 1;
            curmax = max(curmax, {ro[id], id});
        } else
        {
            if (curmax.first > r[s.id])
            {
                ll best = (ll)(r[s.id] - l[s.id]) * c[s.id];
                if (answer.first < best)
                {
                    answer.first = best;
                    answer.second = {curmax.second, s.id};
                }
            }
        }
    }
    cout << answer.first << endl;
    if (answer.first != 0)
    {
        cout << answer.second.first + 1 << ' ' << answer.second.second + 1 << endl;
    }
    return 0;
}