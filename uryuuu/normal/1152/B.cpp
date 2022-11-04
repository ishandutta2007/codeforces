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
int q[100];
int main()
{
    int a;
    cin>>a;
    int t=0;
    if(a==1)
    {
        cout<<0<<endl;
        return 0;
    }
    while((1<<t)<a)
    {
        t++;
    }
    if(a==(1<<t)-1)
    {
        cout<<0<<endl;
        return 0;
    }
    int d=t+1;
    int s=0;
    int tt=0;
    while(a!=(1<<d)-1)
    {
        while(((a>>(t))&1)==1)
        {
            t--;
        }
        a^=((1<<(t+1))-1);
        s++;
        q[tt++]=t+1;
        if(a==(1<<d)-1)
            break;
        a+=1;
        s++;
    }
    cout<<s<<endl;
    for(int i=0;i<tt;i++)
        cout<<q[i]<<' ';
    cout<<endl;
    return 0;
}