#include <stdio.h>

using namespace std;

#define maxn 10010

int n, i, j, k, nr, ok;
int t[maxn][4], f[4];
char c1, c2, c3, c4;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%c%c\n", &c1, &c2);
        scanf("%c%c\n", &c4, &c3);
        f[0]=c1-'0';
        f[1]=c2-'0';
        f[2]=c3-'0';
        f[3]=c4-'0';
        for(int j=1; j<=nr; ++j)
        {
            ok=0;
            for(int k=0; k<4; ++k)
            {
                int z=1;
                for(int l=0; l<4; ++l)
                    if(t[j][l]!=f[(l+k)%4])
                    {
                        z=0;
                        break;
                    }
                if(z==1)
                {
                    ok=1;
                    break;
                }
            }
            if(ok==1)
                break;
        }
        if(ok==0)
        {
            ++nr;
            for(int j=0; j<4; ++j)
                t[nr][j]=f[j];
        }
        scanf("%c%c\n", &c1, &c2);
    }
    printf("%d\n", nr);
    return 0;
}