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
int a[200010];
int main()
{
    int n;
    int zd=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        zd=max((int)(upper_bound(a,a+n,a[i]+5)-a)-i,zd);
    }
    cout<<zd<<endl;
    return 0;
}