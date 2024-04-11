#include <cstdio>

using namespace std;

int n, m;
int x1, x2, y1, y2;

int ab(int x)
{
    if(x>0)
        return x;
    return -x;
}

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    if(x1==x2)
    {
        printf("%d %d %d %d\n", x1+y2-y1, y1, x1+y2-y1, y2);
        return 0;
    }

    if(y1==y2)
    {
        printf("%d %d %d %d\n", x1, y1+x2-x1, x2, y2+x2-x1);
        return 0;
    }

    if(ab(x2-x1)!=ab(y2-y1))
    {
        printf("-1\n");
        return 0;
    }

    printf("%d %d %d %d\n", x1, y2, x2, y1);

    return 0;
}