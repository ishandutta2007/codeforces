#include<bits/stdc++.h>
#define ll long long
#define maxn 6005
using namespace std;
int ch[maxn][2];
int fa[maxn],cnt,last,rt;
ll sz[maxn],dis[maxn];
void init()
{
    cnt=0;
    rt=last=++cnt;
    memset(fa,0,sizeof(fa));
    memset(dis,0,sizeof(dis));
    memset(sz,0,sizeof(sz));
    memset(ch,0,sizeof(ch));
}
inline int newnode(int x){dis[++cnt]=x;return cnt;}
void add(int x)
{
    int np=newnode(dis[last]+1),p=last;
    for(;p&&(!ch[p][x]);p=fa[p])ch[p][x]=np;
    if(!p)fa[np]=rt;
    else
    {
        int q=ch[p][x];
        if(dis[q]==dis[p]+1)fa[np]=q;
        else
        {
            int nq=newnode(dis[p]+1);
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for(;ch[p][x]==q;p=fa[p])ch[p][x]=nq;
        }
    }
    last=np;
    sz[np]=1;
}
const int mod = 1000000007;
int m;
int a[maxn],n,ans;
int b[maxn];
int dp[maxn];
int get(int l,int r)
{
	int tot=0;
	for(int i=l;i<=r;++i)tot=tot*2+b[i];
	return tot;
}
void DP(int x,int y)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=y;++i)
	{
		for(int j=1;j<=4;++j)if(i>=j)
		{
			if(j==4)
			{
				int t=get(i-j+1,i);
				if(t==7||t==10||t==12||t==15)continue;
			}
			dp[i]=(dp[i]+dp[i-j])%mod;
		}
	}
	for(int i=x;i<=y;++i)ans=(ans+dp[i])%mod;
}
int main()
{
	init();
	scanf("%d",&m);
	while(m--)
	{
		int x;
		scanf("%d",&x);
		a[++n]=x;
		add(x);
		int L1=dis[fa[last]]+1,L2=dis[last];
		memset(b,0,sizeof(b));
		for(int i=1;i<=L2;++i)b[i]=a[n-i+1];
		DP(L1,L2);
		printf("%d\n",ans);
	}
}