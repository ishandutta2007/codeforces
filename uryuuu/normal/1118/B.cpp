#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int a[200010],s1[200010],s2[200010];
int main()
{
    int n,t=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2)
            a[i]=-a[i];
    }
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    for(int i=1;i<=n;i++)
        s1[i]=s1[i-1]+a[i];
    for(int i=n;i>0;i--)
        s2[i]=s2[i+1]+a[i];
    for(int i=1;i<=n;i++)
    {
        if(s1[i-1]==s2[i+1])
            t++;
    }
    cout<<t<<endl;
    return 0;
}