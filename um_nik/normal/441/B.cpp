#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

int n, p, ans;
pii a[5000];

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a, a + n);
    int idx = 0;
    for (int cur_t = 0; cur_t < 5000; cur_t++)
    {
        int tmp = 0;
        while (idx < n && a[idx].x + 1 < cur_t) idx++;
        if (idx == n)
            break;
        while (idx < n && cur_t >= a[idx].x)
        {
            if (tmp + a[idx].y <= p)
            {
                tmp += a[idx].y;
                idx++;
            }
            else
            {
                a[idx].y -= p - tmp;
                tmp = p;
                break;
            }
        }
        ans += tmp;
    }
    printf("%d\n", ans);
    return 0;
}