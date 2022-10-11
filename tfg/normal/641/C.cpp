#include <iostream>
#include <cstdio>
#include <algorithm>
#define $ ios::sync_with_stdio(0);
#define MAXN 1123456
using namespace std;
int b[2], pos[MAXN];


int main()
{
    int par=0, impar=0, n, m, a, i;
    scanf("%d %d", &n, &m);
    b[0] = -1;
    b[1] = 1;
    while(m--)
    {
        scanf("%d", &a);
        if(a&1)
        {
            scanf("%d", &a);
            par+=a;
            impar+=a;
            par %= n;
            impar %= n;
        }
        else
        {
            par += b[(par&1)];
            impar += b[(!(impar&1))];
        }
    }

    for(i = 1; i<=n; ++i)
    {
        if((i&1))
            a = (i+impar);
        else
            a = (i+par);

        while(a>n)
            a-=n;
        while(a<0)
            a+=n;
        if(a==0)
            a = n;
        pos[a]=i;
    }

    for(i =1; i<=n; ++i)
    {
        if(i>1)
            printf(" ");
        printf("%d", pos[i]);
    }
    printf("\n");

}