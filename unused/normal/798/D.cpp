#include <bits/stdc++.h>
using namespace std;

struct dat
{
    int a, b, idx;
};

dat d[100005];

bool yes[100005];

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i].a;
    for (int i = 0; i < n; i++) cin >> d[i].b;
    for (int i = 0; i < n; i++) d[i].idx = i + 1;
    sort(d, d + n, [](dat a, dat b){return a.a > b.a;});

    int ptr = 0;
    priority_queue<pair<int,int>> pq;
    int cnt = 0;
    for (int i = 0; i < n / 2 + 1; i++)
    {
        while (ptr < n && ptr <= 2 * i)
        {
            pq.emplace(d[ptr].b, d[ptr].idx);
            ++ptr;
        }
        if (pq.empty() == false)
        {
            ++cnt;
            int x = pq.top().second;
            pq.pop();
            yes[x] = true;
        }
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) if (yes[i]) printf("%d ", i);
    printf("\n");
}