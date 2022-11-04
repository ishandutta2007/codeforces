#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int a[110];
int main()
{
    int n,k,s=0,jg=0,dp;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(int i=0;i<k;i++)
    {
        dp=s;
        for(int j=i;j<n;j+=k)
        {
            if(a[j]==1)
                dp--;
            else
                dp++;
        }
        jg=max(jg,abs(dp));
    }
    cout<<jg<<endl;
    return 0;
}