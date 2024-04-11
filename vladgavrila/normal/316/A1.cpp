#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100010

int n, m, n0, pz, sol;
char s[maxn], f[600];

int main()
{
 //   freopen("a.in", "r", stdin);
 //   freopen("a.out", "w", stdout);

    scanf("%s", s+1);
    n=strlen(s+1);

    pz=10;
    sol=1;

    if(s[1]=='?')
        sol=9;

    if(s[1]>='A' && s[1]<='J')
    {
        f[s[1]]=1;
        sol=9;
        pz=9;
    }
    for(int i=2; i<=n; ++i)
    {
        if(s[i]=='?')
            ++n0;
        if(s[i]>='A' && s[i]<='J')
        {
            if(f[s[i]]==0)
            {
                f[s[i]]=1;
                sol=sol*pz;
                pz--;
            }
        }
    }

    printf("%d", sol);
    for(int i=1; i<=n0; ++i)
        printf("0");
    printf("\n");

    return 0;
}