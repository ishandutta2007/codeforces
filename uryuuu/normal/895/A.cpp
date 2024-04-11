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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[400];
int s[400];
int main()
{
    int n;
    cin>>n;
    mm(a);
    mm(s);
    s[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int zx=400;
    for(int i=1;i<=360;i++)
    {
        for(int j=i;j<=360;j++)
        {
            int ss=2*abs(s[j]-s[i]-180);
            zx=min(zx,ss);
        }
    }
    cout<<zx<<endl;
    return 0;
}