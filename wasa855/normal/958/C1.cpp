#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
int m,n;
int sum(int x)
{
    ll c=0,d=0;
    c=a[x]%n;
    d=a[m]-a[x];
    d%=n;
    return c+d;
}
int main()
{
    cin>>m>>n;
    int t;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        t%=n;
        a[i]=a[i-1]+t;
    }
    int maxn=0;
    for(int i=1;i<=m;i++)
    {
        maxn=max(maxn,sum(i));
    }
    cout<<maxn<<endl;
    return 0;
}