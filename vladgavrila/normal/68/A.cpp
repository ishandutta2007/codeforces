#include <stdio.h>

using namespace std;

int n, i, j, k, kk, a, b, sol;
int p[4];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d%d%d%d", &p[0], &p[1], &p[2], &p[3], &a, &b);
    for(int nr=a; nr<=b; ++nr)
    {
        kk=0;
        for(int i=0; i<4 && kk<7; ++i)
        {
            for(int j=0; j<4 && kk<7; ++j)
            {
                if(j==i)
                    continue;
                for(int k=0; k<4 && kk<7; ++k)
                {
                    if(k==i || k==j)
                        continue;
                    for(int l=0; l<4 && kk<7; ++l)
                    {
                        if(l==i || l==j || l==k)
                            continue;
                        if((((nr%p[i])%p[j])%p[k])%p[l]==nr)
                            ++kk;
                    }
                }
            }
        }
        if(kk==7)
            ++sol;
    }
    printf("%d\n", sol);
    return 0;
}