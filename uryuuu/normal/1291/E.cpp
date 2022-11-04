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
const int maxn=600005;
const ll Mod=1e9+7;

int n,k;
string s;
int l[maxn][2],fa[maxn],cnt[maxn];
int getf(int x)
{
    return fa[x]==x?x:fa[x]=getf(fa[x]);
}

int calc(int x)
{
    int y=x<=k?x+k:x-k;
    x=getf(x);
    y=getf(y);
    if(x==0||y==0)
        return cnt[x+y];
    return min(cnt[x],cnt[y]);
}

void merge(int x,int y)
{
    x=getf(x);
    y=getf(y);
    if(y==0)
    {
        swap(x,y);
    }
    fa[y]=x;
    if(x)
    {
        cnt[x]+=cnt[y];
    }
    
}


int main()
{
    sync;
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            if(l[x][0]==0)
                l[x][0]=i;
            else
                l[x][1]=i;
        }
        fa[i]=i;
        fa[i+k]=i+k;
        cnt[i+k]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i][1]==0)
        {
            int x=l[i][0];
            if(x)
            {
                ans-=calc(x);
                if(s[i-1]=='1')
                {
                    fa[getf(x+k)]=0;
                }
                else
                {
                    fa[getf(x)]=0;
                }
                ans+=calc(x);
            }
        }
        
        else
        {
            int x=l[i][0],y=l[i][1];
            if(s[i-1]=='1')
            {
                if(getf(x)!=getf(y))
                {
                    ans-=calc(x);
                    ans-=calc(y);
                    merge(x,y);
                    merge(x+k,y+k);
                    ans+=calc(x);
                }
            }
            else
            {
                if(getf(x+k)!=getf(y))
                {
                    ans-=calc(x);
                    ans-=calc(y);
                    merge(x+k,y);
                    merge(x,y+k);
                    ans+=calc(x);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}