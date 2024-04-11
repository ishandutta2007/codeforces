#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MV 5000000
int moz[MV+1],qzh[MV+1];
void xs()
{
    for(int i=2;i<=MV;i++)
    {
        if(moz[i]) continue;
        long long base=i;
        while(base<=MV)
        {
        for(int j=base;j<=MV;j+=base) moz[j]++;
        base*=i;
        }
    }
    qzh[1]=0;
    for(int i=2;i<=MV;i++) qzh[i]=qzh[i-1]+moz[i];
}
int main()
{
    xs(); int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",qzh[a]-qzh[b]);
    }
}