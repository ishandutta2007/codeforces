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
int a[200010],b[200010],c[200010],d[200010];
int main()
{
    int n;
    cin>>n;
    b[0]=0;
    int zd=-300000;
    int flag=0;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i]+b[i-1];
        if(b[i]>0)
            flag=1;
        zd=max(b[i],zd);
    }
    int zx=n;
    if(flag)
        zx=n-zd;
    for(int i=0;i<n;i++)
    {
        c[i]=zx+b[i];
        if(c[i]<=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        d[c[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        cout<<c[i]<<' ';
    cout<<endl;
    return 0;
}