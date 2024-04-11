#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 10;
vector <int> ans[N];
int a[N];
bool used[N];

int main()
{
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a, a + n, [](int a, int b){ return (a & 1) < (b & 1); });
    
    int t = 0;
    for (int i = 0; i < n;)
    {
        if (t == p)
            break;
        if (a[i] % 2 == 0)
        {
            used[i] = 1;
            ans[t].push_back(a[i]);
            t++;
            i++;
        }
        else if (a[i] % 2 == 1 && i + 1 < n)
        {
            used[i] = used[i + 1] = 1;
            ans[t].push_back(a[i]);
            ans[t].push_back(a[i + 1]);
            t++;
            i += 2;
        }
        else if (a[i] % 2 == 1 && i + 1 == n)
            break;
        if (t == p)
            break;
    }
    
    if (t != p)
    {
        puts("NO");
        return 0;
    }
    
    if (t == k)
    {
        int sum = 0;
        for (int s = n - 1; s >= 0; s--)
        {
            if (!used[s])
            {
                ans[0].push_back(a[s]);
                sum += a[s];
            }
        }
        if (sum & 1)
        {
            puts("NO");
            return 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (t == k)
            break;
        if (t == k - 1)
        {
            int sum = 0;
            for (int q = i; q >= 0; q--)
            {
                if (used[q])
                    break;
                ans[t].push_back(a[q]);
                sum += a[q];
            }
            if (!(sum & 1))
            {
                puts("NO");
                return 0;
            }
            t++;
            break;
        }
        ans[t].push_back(a[i]);
        t++;
    }
    puts("YES");
    for (int i = 0; i < t; i++)
    {
        printf("%d ", (int)ans[i].size());
        for (int  s : ans[i]) printf("%d ", s);
        puts("");
    }
    
    return 0;
}