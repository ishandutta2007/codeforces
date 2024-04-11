#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int n, a[500001], ans[500001];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i + 2 * n] = a[i];
    }
    deque<int> q;
    int r = 1;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.front() < i)
        {
            q.pop_front();
        }
        while (q.empty() || 2 * a[r] >= a[q.front()])
        {
            while (!q.empty() && a[r] >= a[q.back()])
            {
                q.pop_back();
            }
            q.push_back(r++);
            if (r > 3 * n)
            {
                break;
            }
        }
        if (r > 3 * n)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = r - i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}