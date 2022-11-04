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
const ll mod=1e9+7;
int a[200010],b[10];
int main()
{
    int t;
    cin>>t;
    string aa;
    cin>>aa;
    for(int i=0;i<t;i++)
    {
        a[i]=aa[i]-'0';
    }
    for(int i=1;i<=9;i++)
    {
        cin>>b[i];
    }
    int d=t;
    int tt=0;
    while(tt<t)
    {
        if(a[tt]<b[a[tt]])
            break;
        tt++;
    }
    while(tt<t)
    {
        a[tt]=b[a[tt]];
        if(a[tt+1]>b[a[tt+1]]||tt==t-1)
            break;
        tt++;
    }
    for(int i=0;i<t;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}