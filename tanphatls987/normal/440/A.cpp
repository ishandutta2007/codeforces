#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100000;

int h[maxi]={0},n,i,tmp;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        h[tmp]=1;
    }
    for(i=1;i<=n;i++) if (!h[i]) printf("%d",i);
}