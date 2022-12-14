#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=2e5+10;
const ll mod=998244353;
int c[maxn];
int f(vi v)
{
    int n=v.size();
    for(int i=1;i<n;i++)if(n%i==0)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=j;k<n;k+=i)
            {
                if(k+i>=n)return i;
                if(c[v[k]]!=c[v[k+i]])break;
            }
        }
    }
    return n;
}

int solve()
{
    int n,ret=maxn;scanf("%d",&n);
    int p[maxn];
    bool vis[maxn]={0};
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        vi v;
        for(int j=i;!vis[j];j=p[j])
        {
            v.push_back(j);
            vis[j]=1;
        }
        ret=min(ret,f(v));
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
	return 0;
}