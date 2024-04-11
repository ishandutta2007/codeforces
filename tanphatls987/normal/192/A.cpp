#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

int compar(const void*x,const void*y)
{
    return *(int*)x-*(int*)y;
}
int b[maxi+1],val,n,r,i;
int main()
{
    scanf("%ld",&n);
    n*=2;
    r=trunc(sqrt(n)+1);
    for(i=0;i<r;i++) b[i]=(i+1)*(i+2);
    for(i=0;i<r;i++)
    {
        val=n-b[i];
        if (bsearch(&val,b,r,sizeof(int),compar)!=NULL)
        {
            printf("YES");return 0;
        }
    }
    printf("NO");
}