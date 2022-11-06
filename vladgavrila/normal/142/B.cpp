#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    if(n>m)
        swap(n, m);

    if(n==1)
    {
        printf("%d\n", m);
        return 0;
    }
    if(n==2)
    {
        if(m%4==1)
            printf("%d\n", m/4*4+2);
        if(m%4==2)
            printf("%d\n", m/4*4+4);
        if(m%4==3)
            printf("%d\n", m/4*4+4);
        if(m%4==0)
            printf("%d\n", m);
        return 0;
    }
    if(n%2==1 && m%2==1)
    {
        printf("%d\n", (n*m)/2+1);
        return 0;
    }
    printf("%d\n", n*m/2);
    return 0;
}