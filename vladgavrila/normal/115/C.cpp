#include <cstdio>

using namespace std;

#define maxn 500010
#define mod 1000003

int n, m, nl, sol, imp;
int v[maxn];
char s[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d%d\n", &n, &m);
    for(int i=1; i<=m; ++i)
        v[i]=-1;
    for(int i=1; i<=n; ++i)
    {
        scanf("%s", s+1);
        imp=-1;
        for(int j=1; j<=m; ++j)
        {
            if(s[j]=='.')
                continue;
            s[j]-='1';
            if(s[j]==3)
                s[j]=2;
            else
            if(s[j]==2)
                s[j]=3;
            int il=(j%2)^(s[j]/2), ic=(i%2)^(s[j]%2);
            if((il!=imp && imp!=-1)||(ic!=v[j] && v[j]!=-1))
            {
                printf("0\n");
                return 0;
            }

            imp=il;
            v[j]=ic;
        }
        if(imp==-1)
            ++nl;
    }

    for(int i=1; i<=m; ++i)
        if(v[i]==-1)
            ++nl;

    sol=1;
    for(int i=1; i<=nl; ++i)
    {
        sol=sol*2;
        while(sol>=mod)
            sol-=mod;
    }

    printf("%d\n", sol);

    return 0;
}