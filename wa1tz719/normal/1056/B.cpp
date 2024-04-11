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
    int i;
    long long ans=0;
    for (i=0;i<m;i++)
    {
        int t1=n/m;
        if ((n%m>=i)&&(i!=0))
        {
            t1++;
        }
        int j;
        for (j=0;j<m;j++)
        {
            int t2=n/m;
            if ((n%m>=j)&&(j!=0))
            {
                t2++;
            }
            if ((i*i+j*j)%m==0)
            {
                ans+=(long long)t1*t2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}