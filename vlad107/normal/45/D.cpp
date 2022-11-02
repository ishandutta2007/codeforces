#include <cstdio>
#include <memory.h>
#include <algorithm>

#define N 150

int n, l[N], r[N], a[N];
bool used[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &l[i], &r[i]);
    memset(used, false, sizeof(used));
    int pans = 0;
    for (int i = 0; i < n; i++)
    {
        int id = -1; pans++;
        for (int j = 0; j < n; j++)
            if (!used[j])
            {
                if (l[j] < pans)
                    l[j] = pans;
                if (pans >= l[j] && (id == -1 || r[j] < r[id]))
                    id = j;
            }
        if (id == -1)
        {
            for (int j = 0; j < n; j++)
                if (!used[j] && (id == -1 || l[j] < l[id] || (l[j] == l[id] && r[j] < r[id])))
                    id = j;
            pans = l[id];
        }
        a[id] = pans;
        used[id] = true;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}