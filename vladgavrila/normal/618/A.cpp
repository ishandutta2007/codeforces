#include <cstdio>

using namespace std;

int n, m;

int main()
{
    scanf("%d", &n);
    for(int i=20; i>=0; --i)
    {
        if((n>>i)&1)
            printf("%d ", i+1);
    }
    printf("\n");
    return 0;
}