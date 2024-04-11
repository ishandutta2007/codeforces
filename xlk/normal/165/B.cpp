#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
inline bool check(int v)
{
    int p=1;
    long long tot=0;
    while(v/p)
    {
        tot+=v/p;
        p*=k;
        if(tot>=n) return true;
    }
    return tot>=n;
}
int main()
{
    scanf("%d%d",&n,&k);
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}