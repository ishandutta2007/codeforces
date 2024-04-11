#include <cstdio>

using namespace std;

int n, x;

int main()
{
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    scanf("%d", &n);
    x=0;
    for(int i=1; i<=n; x=(x+i)%n, ++i)
    {
        if(i==1)
            continue;
        printf("%d ", x+1);
    }
    printf("\n");

    return 0;
}