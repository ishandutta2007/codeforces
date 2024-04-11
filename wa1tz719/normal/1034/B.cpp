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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    if (n>m)
    {
        swap(n,m);
    }
    if (n==1)
    {
        printf("%d\n",m/6*6+max(0,(m%6-3)*2));
    }
    else if (n==2)
    {
        if (m<=2)
        {
            printf("0\n");
        }
        else if ((m==7)||(m==3))
        {
            printf("%d\n",m*2-2);
        }
        else
        {
            printf("%d\n",m*2);
        }
    }
    else
    {
        cout<<(long long)n*m/2*2<<endl;
    }
    return 0;
}