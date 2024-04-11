#include <stdio.h>
#include <algorithm>

using namespace std;

int n, i, nr, j, k, a, b;
int v[4];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &nr);
    v[nr]=1;
    while(scanf("%d%d", &a, &b)==2)
        swap(v[a], v[b]);
    for(int i=1; i<=3; ++i)
        if(v[i])
            printf("%d\n", i);
    return 0;
}