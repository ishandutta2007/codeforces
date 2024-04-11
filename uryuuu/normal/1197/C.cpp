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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 20010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[300005],sum[300005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum[0]=0;
    for(int i=1;i<n;i++)
    {
        sum[i]=a[i]-a[i-1];
    }
    sort(sum,sum+n,cmp);
    int s=0;
    for(int i=0;i<k-1;i++)
    {
        s+=sum[i];
    }
    cout<<a[n-1]-a[0]-s<<endl;
    return 0;
}