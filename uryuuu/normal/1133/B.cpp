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
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k;
    int aa;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>aa;
        a[aa%k]++;
    }
    int s=0;
    s+=a[0]/2;
    for(int i=1;i<=k/2;i++)
    {
        if(2*i==k)
            s+=(a[i]/2);
        else
            s+=min(a[i],a[k-i]);
    }
    cout<<s*2<<endl;
    return 0;
}