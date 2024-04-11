#include<bits/stdc++.h>
const int N = 100010;

int n, m, d[N], a[N], d1[N], d2[N];

bool check(int mid)
{
    int day = 0;
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    for (int i = 0; i < mid; i++)
        d1[d[i]] = i;
    for (int i = 1; i <= m; i++)
    {
        if (!d1[i])
    		return false;
        d2[d1[i]] = i;
    }    
    for (int i = 0; i < mid; i++)
    {
        if (d2[i])
        {
           if (day < a[d2[i] - 1])
        	   	return false;
            day -= a[d2[i] - 1];
        }
        else
            day++;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    int left = 0, right = n;
    while (left < right)
    {
          int mid = left + right >> 1;
          if (check(mid))
              right = mid;
          else
              left = mid + 1;
    }
    if (check(left))
        printf("%d", left);
    else
        printf("-1");
    return 0;
}