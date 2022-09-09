#include <stdio.h>
#define ll long long
const int N=400050;
const int L=20;
ll par[N][L],nxt[N][L],Max[N][L],dep[N];
ll sum[N][L];
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	ll q,i,n=1,t;
	ll p,w,c,x;
	dep[1]=1;
	scanf("%lld",&q);
	ll ans=0;
	while(q--)
	{
		scanf("%lld",&t);
		if(t==1)
		{
			scanf("%lld %lld",&p,&w);
			p^=ans;
			w^=ans;
			//printf("%i %lld %lld\n",t,p,w);
			n++;
			par[n][0]=p;
			Max[n][0]=w;
			for(i=1;i<L;i++)
			{
				par[n][i]=par[par[n][i-1]][i-1];
				Max[n][i]=max(Max[n][i-1],Max[par[n][i-1]][i-1]);
			}
			int u=par[n][0];
			for(i=L-1;~i;i--) if(Max[u][i]<w) u=par[u][i];
			//if(u!=par[n][0]) u=par[u][0];
			//printf("%i %lld\n",u,sum[u][0]);
			nxt[n][0]=u;
			dep[n]=dep[u]+1;
			sum[n][0]=w;
			//printf("Sum:%lld ",sum[n][0]);
			for(i=1;i<L;i++)
			{
				nxt[n][i]=nxt[nxt[n][i-1]][i-1];
				sum[n][i]=sum[n][i-1]+sum[nxt[n][i-1]][i-1];
				//if(i==1)
				//{
				//	printf("->%lld %lld %lld<- ",sum[n][i-1],sum[nxt[n][i-1]][i-1],nxt[n][i-1]);
				//}
				//printf("%lld ",sum[n][i]);
			}
			//printf("\n");
		}
		else
		{
			scanf("%lld %lld",&c,&x);
			c^=ans;
			x^=ans;
			//printf("%i %lld %lld\n",t,c,x);
			p=c;
			ans=0;
			for(i=L-1;~i;i--)
			{
				//printf("sum:%lld c:%lld i:%lld nxt:%lld\n",sum[c][i],c,i,nxt[c][0]);
				if(sum[c][i]<=x)
				{
					x-=sum[c][i];
					ans+=(1<<i);
					c=nxt[c][i];
				}
			}
			//printf("%lld\n",ans);
			ans=min(ans,dep[p]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}