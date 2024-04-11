#include <bits/stdc++.h>
using namespace std;

int tab[1001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if(n == 4 || k < n + 1)
    {
        puts("-1");
        return 0;
    }
    set<int> s;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    s.erase(a);
    s.erase(b);
    s.erase(c);
    s.erase(d);
    tab[0] = a;
    tab[1] = c;
    tab[n-2] = d;
    tab[n-1] = b;
    for(int i = 2; i < n - 2; i++)
    {
        tab[i] = *s.begin();
        s.erase(s.begin());
    }
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    puts("");
    printf("%d %d ", c, a);
    for(int i = 2; i < n - 2; i++)
        printf("%d ", tab[i]);
    printf("%d %d\n", b, d);
}