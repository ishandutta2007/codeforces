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

int main()
{   
  
    int n, m[100005], a, i, ans=0;
    scanf("%d %d", &n, &m[0]);
    for(i=1; i<n; i++)
    {
        scanf("%d", &a);
        m[i]=m[i-1]+a;
    }
    for(i=0; i<n-1; i++)
        if (m[i]==m[n-1]-m[i]) ans++;
    printf("%d\n", ans);
}