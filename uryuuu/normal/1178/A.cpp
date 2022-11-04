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
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[105];
int b[105];
int main()
{
    int n;
    cin>>n;
    int k=1,sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int w=a[1]/2,s=a[1];
    b[0]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=w)
        {
            b[k++]=i;
            s+=a[i];
        }
    }
    if(2*s<=sum)
        cout<<0<<endl;
    else
    {
        cout<<k<<endl;
        for(int i=0;i<k;i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}