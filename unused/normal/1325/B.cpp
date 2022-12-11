#include <bits/stdc++.h>
using namespace std;
 
int d[100005];
 
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) scanf("%d",&d[i]);
        printf("%zd\n", unordered_set<int>{d, d + n}.size());
    }
}