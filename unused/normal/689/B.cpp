#include <bits/stdc++.h>
using namespace std;

int dat[200005];
int visit[200005];
int n;

vector<int> nxt(int t)
{
    vector<int> ret;
    ret.push_back(dat[t]);
    if(t>1)ret.push_back(t-1);
    if(t<n)ret.push_back(t+1);
    return ret;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&dat[i]);
    }

    queue<int> que;
    visit[1] = 1;
    que.push(1);
    while (que.empty() == false)
    {
        int t = que.front();
        que.pop();

        for (int x : nxt(t))
        {
            if (visit[x]) continue;
            visit[x] = visit[t] + 1;
            que.push(x);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", visit[i] - 1);
    printf("\n");
}