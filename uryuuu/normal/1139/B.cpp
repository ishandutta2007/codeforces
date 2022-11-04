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
const int maxn=100005;
ll a[200010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll s=a[n-1];
    ll zd=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
            if(zd==0)
                break;
            if(a[i]<zd)
            {
                s+=a[i];
                zd=a[i];
            }
            else
            {
                zd--;
                s+=zd;
            }
    }
    cout<<s<<endl;
    return 0;
}