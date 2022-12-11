#include <cstdio>
#include <algorithm>
using namespace std;

int d[100005];

int main()
{
    int T; scanf("%d",&T); while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) scanf("%d", &d[i]);
        sort(d, d + n);
        d[n] = 1e9;
        for (int i = n - 1; i >= 0; i--)
        {
            if (d[i] + 1 < d[i + 1]) ++d[i];
        }
        sort(d, d + n);
        printf("%zd\n", unique(d, d + n) - d);
    }
}