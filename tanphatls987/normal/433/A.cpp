#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

const int maxi=100;

int a[100]={0},n,i,j,sum=0,tmp;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        a[tmp/100]++;
        sum+=tmp/100;
    }
    if (sum%2) printf("NO");else
    {
        sum/=2;
        if (a[1]>=sum%2) printf("YES");else printf("NO");
    }

}