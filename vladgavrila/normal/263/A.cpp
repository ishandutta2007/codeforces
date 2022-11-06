#include <cstdio>

using namespace std;

int x, y, c;

int ab(int a)
{
    if(a<0)
        return -a;
    return a;
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    for(int i=1; i<=5; ++i)
        for(int j=1; j<=5; ++j)
        {
            scanf("%d", &c);
            if(c==1)
            {
                x=i;
                y=j;
            }
        }

    printf("%d\n", ab(x-3)+ab(y-3));

    return 0;
}