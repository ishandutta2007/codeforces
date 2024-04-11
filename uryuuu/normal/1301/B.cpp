#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;


int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int zx=1e9+700,zd=-1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==-1)
                sum++;
        }
        if(sum==n)
        {
            cout<<0<<' '<<42<<endl;
            continue;
        }
        int s=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=-1)
            {
                if(i-1>=1)
                {
                    if(a[i-1]==-1)
                    {
                        zx=min(a[i],zx);
                        zd=max(a[i],zd);
                    }
                    else
                        s=max(abs(a[i]-a[i-1]),s);
                }
                if(i+1<=n)
                {
                    if(a[i+1]==-1)
                    {
                        zx=min(a[i],zx);
                        zd=max(a[i],zd);
                    }
                    else
                        s=max(abs(a[i]-a[i+1]),s);
                }
            }
        }
        int k=(zd+zx)/2;
        s=max(abs(zd-k),s);
        s=max(abs(zx-k),s);
        cout<<s<<' '<<k<<endl;
    }
    
    return 0;
}