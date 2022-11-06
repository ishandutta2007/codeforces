#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 400

int n, i, sol, j, k, ok, lg[maxn];
char s[maxn][maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        fgets(s[i], 1000, stdin);
        lg[i]=strlen(s[i]);
        ok=1;
        for(int j=1; j<i; ++j)
        {
            if(lg[j]!=lg[i])
                continue;
            for(k=0; k<lg[i]; ++k)
                if(s[i][k]!=s[j][k])
                    break;
            if(k==lg[i])
            {
                ok=0;
                break;
            }
        }
        sol+=ok;
    }
    printf("%d\n", sol);
    return 0;
}