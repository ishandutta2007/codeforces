#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 50010

int n, i, j, k, ok, nr, start, f[maxn];
char s[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", &s);
    n=strlen(s);
    nr=0;
    for(int i=0; i<n; ++i)
        if(s[i]==',')
        {
            f[nr]=1;
            nr=0;
        }
        else
            nr=nr*10+s[i]-'0';
    if(nr!=0)
        f[nr]=1;
    for(int i=1; i<5000; ++i)
    {
        if(start==0 && f[i]==1)
        {
            start=i;
        }
        else
        if(f[i]==0 && start>0)
        {
            if(!ok)
                ok=1;
            else
                printf(",");
            if(i-start==1)
                printf("%d", start);
            else
                printf("%d-%d", start, i-1);
            start=0;
        }
    }
    printf("\n");
    return 0;
}