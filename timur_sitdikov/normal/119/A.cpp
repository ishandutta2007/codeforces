#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int cmp(const void *c1, const void *c2)
{return 0;}

int gcd(int a, int b)
{return b? gcd(b, a%b): a;}

int main()
{   
  
    int a[2], i, n;
    scanf("%d %d %d", &a[0], &a[1], &n);
    for(i=0; n; i^=1)
    {
        n-=gcd(a[i], n);
    }
    printf("%d\n", 1-i);
}