#include <cstdio>
#include <algorithm>

using namespace std;

int d1,d2,d3;

int main()
{
    scanf("%d%d%d", &d1, &d2, &d3);
    if(d1>d2)
        swap(d1, d2);

    printf("%d\n", min(d1+d2+d3, min(2*d1+2*d2, 2*d1+2*d3)));

    return 0;
}