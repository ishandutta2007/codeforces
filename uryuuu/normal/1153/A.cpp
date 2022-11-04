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
int main()
{
    int n,t,a,d,z=0,tt=inf;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>d;
        while(a<t)
        {
            a+=d;
        }
        if(a==t)
        {
            cout<<i<<endl;
            return 0;
        }
        if(tt>a)
        {
            tt=a;
            z=i;
        }
    }
    cout<<z<<endl;
    return 0;
}