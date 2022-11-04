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
map<pair<int,int>,int>mp;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int a[200010],b[200010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int ans=0;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0&&b[i]==0)
        {
            temp++;
            continue;
        }
        else if(a[i]==0)
            continue;
        if(b[i]==0)
        {
            mp[pair<int,int>(0,1)]++;
            ans=max(ans,mp[pair<int,int>(0,1)]);
            continue;
        }
        int g=gcd(a[i],b[i]);
        int fz=b[i]/g;
        int fm=a[i]/g;
        if(fz<0)
        {
            fz*=-1;
            fm*=-1;
        }
        mp[pair<int,int>(fz,fm)]++;
        ans=max(ans,mp[pair<int,int>(fz,fm)]);
    }
    cout<<ans+temp<<endl;
    return 0;
}