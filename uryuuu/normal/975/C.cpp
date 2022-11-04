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
#define mm(a) memset(a,0,sizeof(a))
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int inf=0x3f3f3f3f;
using namespace std;
const int maxn=2e5+10;
ll a[201000];
ll sum[201000];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i-1];
    }
    ll k;
    ll qq;
    ll xh=0;
    int sc=0;
    for(int i=0;i<q;i++)
    {
        cin>>qq;
        qq+=xh;
        if(sum[n]<=qq)
        {
            cout<<n<<endl;
            xh=0;
            sc=1;
        }
        else
        {
            int l=0,r=n,m;
            while(l<r)
            {
                m=(l+r)/2;
                if(qq>=sum[m])
                    l=m+1;
                else
                    r=m;
            }
            sc=l;
            xh=qq;
            cout<<n-sc+1<<endl;
        }
    }
    return 0;
}