#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100000;

int n,d,i,sum=0,a[maxi];
int main()
{
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if (sum+(n-1)*10>d) printf("-1");
    else printf("%d",(d-sum)/5);
}