#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char a[201000],b[201000];
int a1[20],b1[20],tot;

int main()
{
    scanf("%s%s",a,b);
    if(strlen(a)!=strlen(b))
    {
        printf("NO\n");
        return 0;
    }
    for(int i=0;a[i];i++)
        if(a[i]!=b[i])
        {
            a1[++tot]=a[i];
            b1[tot]=b[i];
        }
    if(tot!=2)
    {
        printf("NO\n");
        return 0;
    }
    if(a1[1]!=b1[2]||a1[2]!=b1[1])
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}