#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 2010

int n, m, sol, cs;
char s1[maxn], s2[maxn];

char getcar(int pz)
{
    if(pz>=0 && pz<n)
        return s1[pz];
    return 0;
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%s%s", s1, s2);

    n=strlen(s1);
    m=strlen(s2);
    sol=maxn;

    for(int i=-2010; i<=2010; ++i)
    {
        cs=0;
        for(int j=0; j<m; ++j)
            if(getcar(i+j)!=s2[j])
                ++cs;
        sol=min(sol, cs);
    }

    printf("%d\n", sol);

    return 0;
}