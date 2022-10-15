#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int t, n;
priority_queue<int> q;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        int ans = 0;
        while (!q.empty())
        {
            int tmp = q.top();
            q.pop();
            while ((tmp & 1) && !q.empty())
            {
                tmp = q.top();
                q.pop();
            }
            if (!(tmp % 2))
            {
                ans++;
                q.push(tmp / 2);
                while (!q.empty() && q.top() == tmp)
                {
                    q.pop();
                    q.push(tmp / 2);
                }
            }
            else
            {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}