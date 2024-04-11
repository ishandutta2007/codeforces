#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int x[1005];
double y[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,r;
    scanf("%d%d",&n,&r);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        int j;
        double now_val=r;
        for (j=0;j<i;j++)
        {
            double t=r*r*4;
            t-=(x[j]-x[i])*(x[j]-x[i]);
            now_val=max(now_val,y[j]+sqrt(t));
        }
        y[i]=now_val;
        printf("%.12lf ",now_val);
    }
    return 0;
}