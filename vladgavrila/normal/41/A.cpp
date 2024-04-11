#include <stdio.h>
#include <cstring>

using namespace std;

#define maxn 220

int n, i, j, k, l1, l2;
char s1[maxn], s2[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", s1+1);
    scanf("%s", s2+1);
    l1=strlen(s1+1);
    l2=strlen(s2+1);
    if(l1!=l2)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=1; i<=l1; ++i)
    {
        if(s1[i]!=s2[l1-i+1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}