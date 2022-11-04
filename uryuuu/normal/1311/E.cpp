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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=5010;
const ll Mod=1000000007;

int fa[maxn],l[maxn],r[maxn],n,d,t,idx;

int getmin(int x)
{
    int ans=0,i=0;
    while(x)
    {
        ans+=i*min(x,1<<i);
        x-=min(x,1<<i);
        i++;
    }
    return ans;
}

int dfs(int u,int n,int d)
{
    if(n==1)
        return 1;
    for(int i=0;i<n;i++)
    {
        if(l[i]+l[n-1-i]<=d-n+1&&d-n+1<=r[i]+r[n-1+i])
        {
            for(int j=l[i],k;j<=r[i]&&j<=d;j++)
            {
                k=d-n+1-j;
                if(l[n-i-1]>k||k>r[n-i-1])
                    continue;
                if(i)
                {
                    fa[++idx]=u;
                    dfs(idx,i,j);
                }
                if(n-1-i)
                {
                    fa[++idx]=u;
                    dfs(idx,n-i-1,d-n+1-j);
                }
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    sync;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        idx=1;
        for(int i=0;i<=n;i++)
        {
            l[i]=getmin(i);
            r[i]=i*(i-1)/2;
        }
        if(dfs(1,n,d))
        {
            cout<<"YES"<<endl;
            for(int i=2;i<=n;i++)
                cout<<fa[i]<<' ';
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}