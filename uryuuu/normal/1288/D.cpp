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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005;
const ll Mod=1e9+7;

int n,m;
int a[maxn][10],mk[maxn],v[maxn],aa,bb;;

int check(int mid)
{
    for(int i=1;i<=n;i++)
    {
        mk[i]=0;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]>=mid)
                mk[i]|=1<<j;
        }
    }
    for(int i=0;i<1<<m;i++)
        v[i]=0;
    for(int j=n;j>0;j--)
        v[mk[j]]=j;
    for(int i=0;i<1<<m;i++)
    {
        if(v[i])
            for(int j=0;j<1<<m;j++)
            {
                if(v[j]&&(i|j)==(1<<m)-1)
                {
                    aa=v[i];
                    bb=v[j];
                    return 1;
                }
            }
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            
        }
    }
    int l=0,r=1e9,mid;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    check(l);
    cout<<aa<<' '<<bb<<endl;
    return 0;
}