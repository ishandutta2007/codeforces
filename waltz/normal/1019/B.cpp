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
int n;
int query(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int a;
    scanf("%d",&a);
    printf("? %d\n",x+n/2);
    fflush(stdout);
    int b;
    scanf("%d",&b);
    if (a<b) return -1;
    if (a>b) return 1;
    return 0;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    if (n%4==2)
    {
        puts("! -1");
        fflush(stdout);
        return 0;
    }
    int l=2,r=n/2;
    int res=query(1);
    if (res==0)
    {
        answer(1);
        return 0;
    }
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        int k=query(mid);
        if (k==0)
        {
            answer(mid);
            return 0;
        }
        if (k==res)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return 0;
}