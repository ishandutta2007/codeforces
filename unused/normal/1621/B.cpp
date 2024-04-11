#include <bits/stdc++.h>
using namespace std;
 
int l[100005], r[100005], c[100005];
 
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int loidx = -1, hiidx = -1, maxidx = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&l[i],&r[i],&c[i]);
            if (loidx == -1) loidx = i;
            else if (l[loidx] > l[i] || (l[loidx] == l[i] && c[loidx] > c[i]))
            {
                loidx = i;
            }
            if (hiidx == -1) hiidx = i;
            else if (r[hiidx] < r[i] || (r[hiidx] == r[i] && c[hiidx] > c[i]))
            {
                hiidx = i;
            }
            if (maxidx == -1) maxidx = i;
            else if (r[maxidx] - l[maxidx] < r[i] - l[i] ||
                (r[maxidx] - l[maxidx] == r[i] - l[i] && c[maxidx] > c[i]))
                maxidx = i;
                
            int ans = c[loidx] + c[hiidx];
            if (r[maxidx] == r[hiidx] && l[maxidx] == l[loidx])
                ans = min(ans, c[maxidx]);
            printf("%d\n", ans);
        }
    }
}