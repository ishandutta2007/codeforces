#include <bits/stdc++.h>
using namespace std;

int a[200005];
int w[200005];

int main()
{
    int n;
    scanf("%d",&n);

    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] == 0)
        {
            que.push(i);
            w[i] = 1;
        }
    }
    w[0] = w[n + 1] = 1e9;
    while (que.empty() == false)
    {
        int t = que.front(); que.pop();
        if (w[t - 1] == 0) que.push(t - 1), w[t - 1] = w[t] + 1;
        if (w[t + 1] == 0) que.push(t + 1), w[t + 1] = w[t] + 1;
    }

    for (int i = 1; i <= n; i++) printf("%d ", w[i] - 1);
    printf("\n");
}