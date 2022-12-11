#include <bits/stdc++.h>
using namespace std;

int mul[100005];
int n;

map<pair<int, int>, int> visit;

int solve(int a, int b, int h, int w)
{
    visit.clear();

    int X = (a + h - 1) / h;
    int Y = (b + w - 1) / w;

    queue<map<pair<int, int>, int>::iterator> que;
    que.push(visit.insert({{1, 1}, 0}).first);

    while (que.empty() == false)
    {
        auto itr = que.front();
        que.pop();

        int nx, ny, idx;
        tie(nx, ny) = itr->first;
        idx = itr->second;

        if (nx >= X && ny >= Y)
        {
            return idx;
        }

        if (idx == n) continue;

        auto res = visit.insert({{min(nx * 1ll * mul[idx], X + 0LL), ny}, idx + 1});
        if (res.second) que.push(res.first);
        res = visit.insert({{nx, min(ny * 1ll * mul[idx], Y + 0LL)}, idx + 1});
        if (res.second) que.push(res.first);
    }

    return INT_MAX;
}

int main()
{
    int a, b, h, w;
    scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
    for (int i = 0; i < n; i++) scanf("%d",&mul[i]);
    sort(mul, mul + n, greater<>());

    int ans = min(solve(a, b, h, w), solve(b, a, h, w));
    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}