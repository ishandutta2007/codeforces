#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t, n, num[100001];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<int> v;
        memset(num, 0, sizeof(num));
        for (int i = 50000; i >= 1; i--)
        {
            while ((long long)i * (i + 1) / 2 <= n)
            {
                n -= i * (i + 1) / 2;
                num[i]++;
            }
        }
        v.push_back(7);
        v.push_back(3);
        for (int i = 1; i <= 50000; i++)
        {
            v.push_back(3);
            while (num[i]--)
            {
                v.push_back(1);
            }
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            printf("%d", v[i]);
        }
        printf("\n");
    }
    return 0;
}