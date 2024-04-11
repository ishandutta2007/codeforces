#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;


int main()
{   
  
    int n, i, j, lim;
    scanf("%d", &n);
    for(i=0; i<2*n+1; i++)
    {
        lim=(i>n? 2*n-i: i);
        for(j=0; j<2*n-2*lim; j++) putchar(' ');
        for(j=0; j<lim; j++) printf("%d ", j);
        printf("%d", j);
        for(j--; j>=0; j--) printf("% d", j);
        putchar('\n');
    }
}