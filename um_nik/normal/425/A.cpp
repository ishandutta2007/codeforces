#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
int ans;
int k;
int sum;
int delta;
int a[300];
int b[4000];
int c[4000];
int d[20], e[20];

int main()
{
    scanf("%d%d", &n, &k);
    ans = -100000000;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ans = max(ans, a[i]);
    }
    for (int l = 0; l < n; l++)
    {
        sum = 0;
        for (int i = 1000; i <= 3000; i++)
            b[i] = c[i] = 0;
        for (int i = 0; i < n; i++)
            c[a[i] + 2000]++;
        for (int r = l; r < n; r++)
        {
            delta = 0;
            c[a[r] + 2000]--;
            b[a[r] + 2000]++;
            sum += a[r];
            int idx1 = 1000;
            int idx2 = 3000;
            int i;
            for (i = 0; i < k; i++)
            {
                while (idx1 <= 3000 && b[idx1] == 0) idx1++;
                while (idx2 >= 1000 && c[idx2] == 0) idx2--;
                if (idx1 == 0 || idx2 == 0)
                    break;
                if (idx1 < idx2)
                {
                    b[idx1]--;
                    c[idx2]--;
                    delta += idx2 - idx1;
                    d[i] = idx1;
                    e[i] = idx2;
                }
                else
                    break;
            }
            ans = max(ans, sum + delta);
            i--;
            while (i >= 0)
            {
                b[d[i]]++;
                c[e[i]]++;
                i--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}