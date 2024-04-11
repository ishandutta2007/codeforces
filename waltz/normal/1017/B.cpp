#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[100005];
char b[100005];
long long cnt0,cnt1,cnt2,cnt3;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    scanf("%s%s",a,b);
    int i;
    for (i=0;i<n;i++)
    {
        if (b[i]=='0')
        {
            if (a[i]=='1')
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        else
        {
            if (a[i]=='1')
            {
                cnt3++;
            }
            else
            {
                cnt2++;
            }
        }
    }
    cout<<cnt0*cnt1+cnt0*cnt3+cnt1*cnt2<<endl;
    return 0;
}