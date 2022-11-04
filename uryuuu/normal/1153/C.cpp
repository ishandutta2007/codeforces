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
string s;
int a[301000];
int main()
{
    int n;
    cin>>n;
    cin>>s;
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            a[i]=-1;
            t++;
        }
        else if(s[i]==')')
            a[i]=1;
        else
            a[i]=0;
    }
    if(a[n-1]==-1)
    {
        cout<<":("<<endl;
        return 0;
    }
    a[n-1]=1;
    int s=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==0)
        {
            if(s!=1&&t<n/2)
            {
                a[i]=-1;
                t++;
            }
            else a[i]=1;
        }
        s+=a[i];
        if(s==0)
        {
            cout<<":("<<endl;
            return 0;
        }
    }
    if(s!=-1)
        cout<<":("<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
                cout<<'(';
            else
                cout<<')';
        }
        cout<<endl;
    }
    return 0;
}