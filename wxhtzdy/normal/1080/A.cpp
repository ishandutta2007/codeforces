#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    int x=(n*2+k-1)/k;
    int y=(n*5+k-1)/k;
    int z=(n*8+k-1)/k;
    printf("%i",x+y+z);
    return 0;
}