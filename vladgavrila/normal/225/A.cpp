#include <cstdio>

using namespace std;

#define maxn 1010

int n, m, top, bot, a[maxn], b[maxn];
int per[maxn], f[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    scanf("%d", &top);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    for(int i=1; i<n; ++i)
    {
        bot=1+2+3+4+5+6-top-a[i]-b[i]-(7-a[i])-(7-b[i]);
        for(int j=1; j<=6; ++j)
            f[j]=0;
        f[a[i+1]]=f[b[i+1]]=f[7-a[i+1]]=f[7-b[i+1]]=f[bot]=1;
        top=0;
        for(int j=1; j<=6; ++j)
            if(f[j]==0)
            {
                if(top!=0)
                {
                    printf("NO\n");
                    return 0;
                }
                top=j;
            }
    }

    printf("YES\n");

    return 0;
}