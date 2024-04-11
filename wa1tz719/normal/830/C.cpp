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
int a[105];
long long points[200005];
long long k;
int n;
bool check(long long x)
{
    int i;
    long long val=0;
    for (i=0;i<n;i++)
    {
        int t=a[i]%x;
        if (t==0) continue;
        val+=x-t;
        if (val>k) return false;
    }
    return true;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin>>n>>k;
    long long ans;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (i=1;i<=1000000;i++)
    {
        long long val=0;
        int j;
        for (j=0;j<n;j++)
        {
            int t=a[j]%i;
            if (t==0) continue;
            val+=i-t;
        }
        if (val<=k) ans=i;
    }
    int sum=2;
    points[0]=999999999999ll;
    points[1]=1000000;
    for (i=1;i<=1000;i++)
    {
        //points!
        int j;
        for (j=0;j<n;j++)
        {
            if (a[j]/i<=1000000) continue;
            points[sum++]=a[j]/i;
            points[sum++]=a[j]/i+1;
        }
    }
    sort(points,points+sum);
    sum=unique(points,points+sum)-points;
    for (i=1;i<sum;i++)
    {
        if (check(points[i]))
        {
            ans=points[i];
            continue;
        }
        if (points[i]==points[i-1]+1) continue;
        long long l=points[i-1]+1,r=points[i]-1;
        for (;l<=r;)
        {
            long long mid=(l+r)/2;
            if (check(mid)) l=mid+1; else r=mid-1;
        }
        if (check(r)) ans=max(ans,r);
    }
    cout<<ans;
    return 0;
}