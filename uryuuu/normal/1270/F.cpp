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
const int maxn=200005;
const ll Mod=1e9+7;

char s[maxn];
int sum[maxn];
pair<int,int>a[maxn];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    int t=max(n/250,(int)sqrt(n));
    int tt=n/t;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+(s[i]=='1');
    }
    ll ans=0;
    for(int i=1;i<=t;i++)
    {
        int r=0,rs=0;
        int num=0;
        for(int l=1;l<=n;l++)
        {
            while(num<i&&r<n)
            {
                num+=(s[++r]=='1');
            }
            rs=max(rs,r);
            while(rs<n&&s[rs+1]!='1')
                rs++;
            if(num==i)
                ans+=(rs-l+1)/i-(r-l)/i;
            num-=s[l]=='1';
        }
    }
    for(int i=1;i<=tt;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[j]=make_pair(j-sum[j]*i,sum[j]);
        }
        a[n+1]=make_pair(0,0);
        sort(a+1,a+n+2);
        for(int l=1,r;l<=n+1;l=r+1)
        {
            r=l;
            while(r<=n&&a[r+1].first==a[l].first)
                r++;
            int ls=l,rs=l;
            for(ls=l;ls<=r;ls++)
            {
                while(rs<=r&&a[rs].second-a[ls].second<=t)
                    rs++;
                ans+=r-rs+1;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}