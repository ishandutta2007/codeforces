#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
int n, q, sz, sum[330][100005];
deque<int> a[330];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    sz = sqrt(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[i / sz].push_back(x);
        sum[i / sz][x]++;
    }
    scanf("%d", &q);
    int last = 0;
    while (q--)
    {
        int op, l, r, k;
        scanf("%d%d%d", &op, &l, &r);
        l = (l + last - 1) % n + 1;
        r = (r + last - 1) % n + 1;
        if (l > r)
        {
            swap(l, r);
        }
        l--;
		int pos1 = l / sz, pos2 = r / sz;
        if (op == 1)
        {
            if (pos1 == pos2)
            {
                r = r % sz - 1;
                int tmp = a[pos2][r];
                a[pos2].erase(a[pos2].begin() + r);
                a[pos1].insert(a[pos1].begin() + l % sz, tmp);
            }
            else
            {
                for (int i = pos1; i < pos2; i++)
                {
                    int tmp = a[i].back();
                    a[i].pop_back();
                    sum[i][tmp]--;
                    a[i + 1].push_front(tmp);
                    sum[i + 1][tmp]++;
                }
                r %= sz;
                int tmp = a[pos2][r];
                a[pos2].erase(a[pos2].begin() + r);
                sum[pos2][tmp]--;
                a[pos1].insert(a[pos1].begin() + l % sz, tmp);
                sum[pos1][tmp]++;
            }
        }
        else
        {
            scanf("%d", &k);
            k = (k + last - 1) % n + 1;
            last = 0;
            if (pos1 == pos2)
            {
                for (int i = l % sz; i < r % sz; i++)
                {
                    last += a[pos1][i] == k;
                }
            }
            else
            {
                for (int i = pos1 + 1; i < pos2; i++)
                {
                    last += sum[i][k];
                }
                for (int i = l % sz; i < (int)a[pos1].size(); i++)
                {
                    last += a[pos1][i] == k;
                }
                for (int i = 0; i < r % sz; i++)
                {
                    last += a[pos2][i] == k;
                }
            }
            printf("%d\n", last);
        }
    }
    return 0;
}