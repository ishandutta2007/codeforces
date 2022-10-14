#include <bits/stdc++.h>

using namespace std;

void test()
{
    int n;
    scanf("%d", &n);
    int tab[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
    }
    sort(tab, tab+n);
    for(int i=1; i<=1024; i++)
    {
        int tabb[n];
        for(int j=0; j<n; j++)
        {
            tabb[j]=tab[j]^i;
        }
        sort(tabb, tabb+n);
        bool ok=1;
        for(int j=0; j<n; j++)
        {
            ok&=(tab[j]==tabb[j]);
        }
        if(ok)
        {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}