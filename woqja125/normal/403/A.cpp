#include<stdio.h>
#include<set>
std::pair<int, int> mkp(int a, int b)
{
    if(a>b) return std::make_pair(b, a);
    else return std::make_pair(a, b);
}
int main()
{
    int T;
    scanf("%d", &T);
    for(; T--;)
    {
        int n, p;
        int i, j;
        scanf("%d%d", &n, &p);
        std::set<std::pair<int, int> > S;
        for(i=1; i<n; i++)
        {
            printf("%d %d\n", i, i+1);
            S.insert(mkp(i, i+1));
        }
        printf("%d 1\n", n);
        S.insert(mkp(1, n));
        for(i=1; i<=n; i++)
        {
            printf("%d %d\n", i, (i+1)%n+1);
            S.insert(mkp(i, (i+1)%n+1));
        }
        for(i=1; i<=n; i++)for(j=i+1; j<=n; j++)
        {
            if(p==0) break;
            if(S.count(mkp(i, j)) == 1) continue;
            p--;
            S.insert(mkp(i, j));
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}