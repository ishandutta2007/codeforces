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
int a[1000005];
int b[1000005];
bool ans;
void get_ans(int l,int r)
{
    if (l==r-1)
    {
        return;
    }
    int mid=(l+r)/2;
    get_ans(l,mid);
    get_ans(mid,r);
    int l1=l,l2=mid;
    int l3=l;
    int i;
    for (i=l;i<r;i++)
    {
        b[i]=a[i];
    }
    for (;;)
    {
        if ((l1<mid)&&((b[l1]<b[l2])||(l2==r)))
        {
            a[l3++]=b[l1];
            l1++;
        }
        else if (l2<r)
        {
            a[l3++]=b[l2];
            int t=mid-l1;
            t&=1;
            ans^=t;
            l2++;
        }
        else
        {
            return;
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    if (n%2==1)
    {
        ans=true;
    }
    else
    {
        ans=false;
    }
    get_ans(0,n);
    if (!ans)
    {
        puts("Petr");
    }
    else
    {
        puts("Um_nik");
    }
    return 0;
}