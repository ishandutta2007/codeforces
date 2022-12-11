#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;
int h[21]={0},n,i,val;
long long ans=0,tmp;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        h[val+10]++;
    }
    for(i=0;i<10;i++) ans+=1LL*h[i]*h[20-i];
    ans+=(1LL*h[10]*(h[10]-1))/2;
    cout<<ans;
}