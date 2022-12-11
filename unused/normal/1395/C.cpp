#include <bits/stdc++.h>
using namespace std;
 
int a[205], b[205];
 
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    for (int i = 0; i < m; i++) scanf("%d",&b[i]);
    int ans = 0;
    int mang = 0;
    for (int i = 1024; i >= 1; i >>= 1)
    {
        bool wrong = false;
        for (int j = 0; j < n; j++)
        {
            bool found = false;
            for (int k = 0; k < m; k++)
            {
                int z = a[j] & b[k];
                if ((z & (mang | i)) == 0)
                {
                    found = true;
                    break;
                }
            }
            
            if (!found)
            {
                wrong = true;
                break;
            }
        }
        if (wrong)
        {
            ans |= i;
        }
        else
        {
            mang |= i;
        }
    }
    printf("%d\n", ans);
}