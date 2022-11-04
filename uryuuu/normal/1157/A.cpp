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
int a[10];
int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<10<<endl;
        return 0;
    }
    int t=0;
    while(n)
    {
        a[t++]=n%10;
        n/=10;
    }
    int s=10;
    if(t==1)
    {
        cout<<9<<endl;
        return 0;
    }
    for(int i=0;i<t-1;i++)
    {
        s=s+(9-a[i]);
    }
    cout<<s<<endl;
    return 0;
}