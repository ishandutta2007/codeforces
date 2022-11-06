#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100010

int n, t, lg, pz;
char s[maxn], cmd[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d\n", &t);
    lg=1;
    s[1]='/';

    while(t--)
    {
        scanf("%s", cmd);

        if(cmd[0]=='p')
        {
            for(int i=1; i<=lg; ++i)
                printf("%c", s[i]);
            printf("\n");
            continue;
        }

        memset(cmd, 0, sizeof(cmd));
        scanf("%s", cmd);
        n=strlen(cmd);
        pz=0;

        if(cmd[0]=='/')
        {
            lg=1;
            s[lg]='/';
            pz=1;
        }

        while(pz<n)
        {
            if(cmd[pz]=='/')
                ++pz;
            if(cmd[pz]=='.')
            {
                --lg;
                while(s[lg]!='/')
                    --lg;
                pz+=2;
            }
            else
            {
                while(cmd[pz]!='/' && pz<n)
                {
                    s[++lg]=cmd[pz];
                    ++pz;
                }
                s[++lg]='/';
            }
        }
    }
    return 0;
}