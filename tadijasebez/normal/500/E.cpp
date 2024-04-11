#include <stdio.h>
#define ll long long
const int N=200050;
const int M=32*N;
const ll inf=2e9+7;
ll p[N],l[N],r[N],par[N][18],sum[N][18];
int ls[M],rs[M],tsz,root;
ll x[M];
ll max(ll a, ll b){ return a>b?a:b;}
void Set(int &c, ll ss, ll se, ll qi, ll val)
{
	if(!c) c=++tsz;
	x[c]=max(x[c],val);
	if(ss==se) return;
	ll mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
ll Get(int c, ll ss, ll se, ll qs, ll qe)
{
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	ll mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&p[i],&l[i]);
	for(i=n;i>=1;i--) r[i]=max(Get(root,1,inf,p[i],p[i]+l[i]),p[i]+l[i]),Set(root,1,inf,p[i],r[i]);
	for(i=n;i>=1;i--)
	{
		int top=n,bot=i+1,mid,ans=0;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(p[mid]>r[i]) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		if(ans)
		{
			par[i][0]=ans;
			sum[i][0]=p[ans]-r[i];
			for(j=1;j<18;j++)
			{
				par[i][j]=par[par[i][j-1]][j-1];
				sum[i][j]=sum[i][j-1]+sum[par[i][j-1]][j-1];
			}
		}
	}
	//for(i=1;i<=n;i++) printf("%i ",r[i]);printf("\n");
	//for(i=1;i<=n;i++) printf("%i ",par[i][0]);printf("\n");
	//for(i=1;i<=n;i++) printf("%i ",sum[i][0]);printf("\n");
	int q,x,y;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		ll sol=inf,tmp=0;
		if(r[x]>=p[y]){ printf("0\n");continue;}
		for(i=17;~i;i--)
		{
			if(par[x][i] && r[par[x][i]]<p[y]) tmp+=sum[x][i],x=par[x][i];
			/*if(r[par[x][i]]>=p[y] || !par[x][i]) sol=min(sol,tmp+sum[x][i]);
			else tmp+=sum[x][i],x=par[x][i];*/
			//printf("%i %i %i\n",i,x,sol);
		}
		sol=tmp+sum[x][0];
		printf("%lld\n",sol);
	}
	return 0;
}