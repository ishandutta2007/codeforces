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
unsigned int a[600005];
unsigned int b[600005];
int n;
unsigned int l;
int flag[200005];
bool check(unsigned int x)
{
    int i;
    for (i=0;i<=n;i++)
    {
        flag[i]=0;
    }
    for (i=0;i<n;i++)
    {
        //can a[i] to ?
        int left_one=lower_bound(b,b+n*3,a[i]+l-x)-b;
        int right_one=upper_bound(b,b+n*3,a[i]+l+x)-b;
        if (right_one-left_one>=n)
        {
            flag[n]++;
        }
        else
        {
            left_one-=i;
            right_one-=i;
            left_one+=n;
            right_one+=n;
            left_one%=n;
            right_one%=n;
            if (left_one>right_one)
            {
                //0 .. right_one and left_one .. n
                flag[n]++;
                flag[left_one]--;
                flag[right_one]++;
            }
            else
            {
                flag[right_one]++;
                flag[left_one]--;
            }
        }
    }
    int sum=0;
    for (i=n;i>=0;i--)
    {
        sum+=flag[i];
        if (sum==n) return true;
    }
    return false;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%u",&n,&l);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%u",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        scanf("%u",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    for (i=0;i<n+n;i++)
    {
        a[i+n]=a[i]+l;
        b[i+n]=b[i]+l;
    }
    int ll=0,rr=l;
    for (;ll<=rr;)
    {
        unsigned int mid=(ll+rr)/2;
        if (check(mid))
        {
            rr=mid-1;
        }
        else
        {
            ll=mid+1;
        }
    }
    printf("%d\n",ll);
    return 0;
}