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
#include <functional>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 11000
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool cmp(int a,int b)
{
    return a>b;
}
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    if(n==3)
    {
        if(a[1]>=a[2]+a[3]||a[2]>=a[1]+a[3]||a[3]>=a[1]+a[2])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(n==4)
    {
        if(a[1]>=a[2]+a[3]||a[2]>=a[1]+a[4]||a[3]>=a[1]+a[4]||a[4]>=a[2]+a[3])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(n>=5)
    {
        if(a[1]>=a[2]+a[3]||a[2]>=a[1]+a[4]||a[3]>=a[1]+a[5]||a[n]>=a[n-1]+a[n-2]||a[n-1]>=a[n]+a[n-3])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=4;i<=n-2;i++)
    {
        if(a[i]>=a[i-2]+a[i+2])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i+=2)
    {
        cout<<a[i]<<' ';
    }
    int k;
    if(n%2)
        k=n-1;
    else
        k=n;
    for(int i=k;i>=1;i-=2)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}