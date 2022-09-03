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
#include <queue>

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

struct tnode
{
    int add;
    pair<int, int> min;
};

const int treesize = 1 << 19;
const int maxn = 500005;
const int inf = 1000000009;

tnode tree[2 * treesize];

int s[maxn], h[maxn];
vector<int> gr[maxn];
int pr[maxn];
priority_queue<pair<int, int>> q;
int n, m;
vector<pair<int, int>> tops;
vector<int> sub[maxn];

inline pair<int, int> getmin(int cur)
{
    if (cur >= treesize) return {tree[cur].add, -(cur - treesize)};
    else return {tree[cur].add + tree[cur].min.first, tree[cur].min.second};
}

void add(int cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
        tree[cur].add += t;
//         cout << "adde " << cur << ' ' << getmin(cur).first << endl;
        return;
    }
    int cm = (cl + cr) / 2;
    add(cur * 2, cl, cm, l, r, t);
    add(cur * 2 + 1, cm + 1, cr, l, r, t);
    tree[cur].min = min(getmin(cur * 2), getmin(cur * 2 + 1));
//     cout << "add " << cur << ' ' << getmin(cur).first << endl;
}

void go(int cur, int pr, int curd, int id)
{
    sub[id].pb(curd);
    for (auto e : gr[cur]) if (e != pr)
    {
        go(e, cur, min(curd, h[e]), id);
    }
}

void addfrom(int h, int t)
{
    int wh = upper_bound(s, s + m, h) - s - 1;
//     cout << "addfrom " << wh << ' ' << t << endl;
    add(1, 0, treesize - 1, 0, wh, t);
}

int findlastneg(int cur, int cl, int cr, int add)
{
    if (cl == cr) return cl;
    int cm = (cl + cr) / 2;
    add += tree[cur].add;
    if (getmin(cur * 2 + 1).first + add >= 0) return findlastneg(cur * 2, cl, cm, add);
    else return findlastneg(cur * 2 + 1, cm + 1, cr, add);
}

void printtree(int cur, int cl, int cr, int add, int to)
{
    if (cl > to) return;
    if (cl == cr)
    {
        printf("%d ", tree[cur].add + add);
        return;
    }
    int cm = (cl + cr) / 2;
    printtree(cur * 2, cl, cm, add + tree[cur].add, to);
    printtree(cur * 2 + 1, cm + 1, cr, add + tree[cur].add, to);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &s[i]);
    sort(s, s + m);
    pr[0] = -1;
    q.push({h[0], 0});
    int last = m - 1;
    while (!q.empty())
    {
        int cur = q.top().second;
        int curd = q.top().first;
        q.pop();
        if (s[last] > curd)
        {
            tops.pb({cur, curd});
            continue;
        }
//         cout << s[last] << " to " << cur << endl;
        last--;
        if (last < 0)
        {
            printf("0\n");
            return 0;
        }
        for (auto e : gr[cur]) if (e != pr[cur])
        {
            pr[e] = cur;
            q.push({min(h[e], curd), e});
        }
    }
    for (int i = 0; i < (int)tops.size(); i++)
    {
        go(tops[i].first, pr[tops[i].first], inf, i);
        sub[i].pb(0);
        sort(sub[i].begin(), sub[i].end());
        reverse(sub[i].begin(), sub[i].end());
    }
//     for (int i = 0; i < (int)tops.size(); i++)
//     {
//         for (int j = 0; j < (int)sub[i].size(); j++) cout << sub[i][j] << ' ';
//         cout << endl;
//         cout << endl;
//     }
    for (int i = 0; i <= last; i++) add(1, 0, treesize - 1, 0, i, -1);
//     printtree(1, 0, treesize - 1, 0, last);
// //     cout << endl;
    for (int i = 0; i < (int)tops.size(); i++)
    {
        for (int j = 0; j < (int)sub[i].size(); j++) addfrom(min(tops[i].second, sub[i][j]), 1);
    }
//     printtree(1, 0, treesize - 1, 0, last);
//     cout << endl;
    int answer = inf;
    for (int i = 0; i < (int)tops.size(); i++)
    {
        for (int j = 0; j < (int)sub[i].size(); j++) addfrom(min(tops[i].second, sub[i][j]), -1);
        for (int j = 0; j < (int)sub[i].size(); j++) addfrom(sub[i][j], 1);
        if (getmin(1).first >= 0)
        {
//             cout << "can " << endl;
//             printtree(1, 0, treesize - 1, 0, last);
//             cout << endl;
            int curh = sub[i][0];
            for (int j = 0; j < (int)sub[i].size(); j++)
            {
                addfrom(curh, -j);
                addfrom(sub[i][j], j);
                curh = sub[i][j];
//                 cout << "curh = " << curh << endl;
//                 printtree(1, 0, treesize - 1, 0, last);
//                 cout << endl;
                pair<int, int> t = getmin(1);
                if (t.first >= 0) continue;
                int wh = findlastneg(1, 0, treesize - 1, 0);
//                 cout << "found " << wh << endl;
                int minh = s[wh];
                answer = min(answer, minh - tops[i].second);
                addfrom(curh, -(j + 1));
                for (int x = j + 1; x < (int)sub[i].size(); x++) addfrom(sub[i][x], -1);
                break;
            }
        } else
        {
            for (int j = 0; j < (int)sub[i].size(); j++) addfrom(sub[i][j], -1);
        }
        for (int j = 0; j < (int)sub[i].size(); j++) addfrom(min(tops[i].second, sub[i][j]), 1);
    }
    if (answer == inf) answer = -1;
    cout << answer << endl;
	return 0;
}