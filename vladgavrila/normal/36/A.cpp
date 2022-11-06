#include <stdio.h>

using namespace std;

#define maxn 1200

int n, i, j, k, pdif, dif;
char s[maxn];
int v[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i)
    {
        if(s[i]=='1')
        {
            v[++v[0]]=i;
        }
    }
    for(int i=2; i<v[0]; ++i)
    {
        if(v[i+1]-v[i]!=v[i]-v[i-1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}