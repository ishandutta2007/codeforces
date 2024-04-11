#include <bits/stdc++.h>
using namespace std;

bool yes[1001];
bool visit[2005];

vector<int> vt;

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    bool lt = false, gt = false;
    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d",&t);
        yes[t] = true;
        if (t == n)
        {
            printf("1\n");
            return 0;
        }
    }

    for (int i = 0; i <= 1000; i++) if (yes[i]) vt.push_back(i - n);

    queue<pair<int,int>> que;
    for (int t : vt) que.emplace(t, 1), visit[1000 + t] = true;

    while (que.empty() == false)
    {
        int a, b;
        tie(a, b) = que.front(); que.pop();

        if (a == 0)
        {
            printf("%d\n", b);
            return 0;
        }

        for (int t : vt)
        {
            int nxt = a + t;
            if (nxt < -1000) continue;
            if (nxt > 1000) continue;
            if (visit[nxt + 1000]) continue;

            visit[nxt + 1000] = true;
            que.emplace(nxt, b + 1);
        }
    }

    printf("-1\n");
    return 0;
}