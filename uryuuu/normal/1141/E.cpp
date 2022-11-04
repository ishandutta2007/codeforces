#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
ll a[200010];
int main()
{
    ll zd=10000055;
    int aa;
    a[0]=0;
    ll h,n;
    cin>>h>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>aa;
        a[i]=a[i-1]+aa;
        zd=min(zd,a[i]);
        if(a[i]+h<=0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    if(a[n]>=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll t=(h+zd)/(-a[n])+1ll*1;
    if((h+zd)%(-a[n])==0)
        t--;
    h+=t*a[n];
    t*=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+h<=0)
        {
            cout<<t+i<<endl;
            break;
        }
    }
    return 0;
}