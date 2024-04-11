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
int a[400010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    int d=0;
    int zd=0;
    int i=0;
    while(i<2*n)
    {
        while(a[i]==1&&i<2*n)
        {
            d++;
            i++;
        }
        zd=max(d,zd);
        d=0;
        i++;
    }
    cout<<zd<<endl;
    return 0;
}