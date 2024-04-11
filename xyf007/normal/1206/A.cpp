#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int n, m, a[101], b[101];
set<int> s;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
        s.insert(b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!s.count(a[i] + b[j]))
            {
                printf("%d %d", a[i], b[j]);
                return 0;
            }
        }
    }
    return 0;
}