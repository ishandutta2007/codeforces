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
int n;
int a[201000],b[201000];
int aa=0,bb=0;
ll sum=0;
int aaa[200010],bbb[200010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(b[a[i]]==n)
        {
            cout<<0<<endl;
            return 0;
        }
    }
        int t=0,d=0;
        for(int i=1;i<=n;i++)
        {
            if(b[a[i]]>=d)
            {
                d=b[a[i]];
                t=i;
            }
        }
        int tt=n;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[t])
                tt--;
        }
        cout<<tt<<endl;
        for(int i=t;i>1;i--)
        {
            if(a[i-1]<a[t])
            {
                cout<<1;
                cout<<' '<<i-1<<' '<<i<<endl;
            }
            if(a[i-1]>a[t])
            {
                cout<<2;
                cout<<' '<<i-1<<' '<<i<<endl;
            }
        }
        for(int i=t;i<n;i++)
        {
            if(a[t]<a[i+1])
            {
                cout<<2<<' ';
                cout<<i+1<<' '<<i<<endl;
            }
            if(a[t]>a[i+1])
            {
                cout<<1<<' ';
                cout<<i+1<<' '<<i<<endl;
            }
        }
    
    return 0;
}