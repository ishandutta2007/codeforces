#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

const int N = (int)1e6;
int a[N];
bool used[N];

int main()
{   
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    
    int ans = n;
    int l = 0, r = n; 
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (2 * m > n)
            r = m;
        else
        {
            bool h = true;
            int it = n - m;
            for (int i = 0; i < m; i++)
            {
                if (a[i] * 2 > a[it])
                    h = false;
                it++;
            }
            if (h)
                l = m;
            else
                r = m;
        }
    }
    
    
    printf("%d", ans - l);
    
    return 0;
}