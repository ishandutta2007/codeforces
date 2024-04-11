#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;

int solve(int x, int y, int tot)
{
    int o2 = tot/2-tot/6;
    int o3 = tot/3-tot/6;
    int both = tot/6;

    x=max(0, x-o2);
    y=max(0, y-o3);
    if(x+y<=both)
        return 1;
    return 0;
}

int main()
{
    scanf("%d%d", &a, &b);

    int left=0, med, sol=200000000, right=200000000;

    while(left<=right)
    {
        med=(left+right)/2;

        if(solve(a, b, med))
        {
            sol=med;
            right=med-1;
        }
        else
            left=med+1;
    }

    printf("%d\n", sol);

    return 0;
}