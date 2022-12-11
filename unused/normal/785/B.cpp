#include <bits/stdc++.h>
using namespace std;

set<int> s1, e1, s2, e2;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s1.insert(a);
        e1.insert(b);
    }

    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s2.insert(a);
        e2.insert(b);
    }

    printf("%d\n", max({0, *s2.rbegin() - *e1.begin(), *s1.rbegin() - *e2.begin()}));
}