#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int S=450;
const int K=2*S;
const ll inf=9e18;
struct Bucket
{
	int sz;
	ll x[K],sol,sum;
	Bucket(){}
	void Calc()
	{
		sum=sol=0;
		for(int i=0;i<sz;i++)
		{
			sol+=x[i]*i-sum;
			sum+=x[i];
		}
	}
	void init(ll a[], int n)
	{
		sz=n;
		for(int i=0;i<sz;i++) x[i]=a[i];
		Calc();
	}
	void Add(ll y)
	{
		sz++;
		for(int i=sz-1;i>=0;i--)
		{
			if(i==0 || x[i-1]<y){ x[i]=y;break;}
			else x[i]=x[i-1];
		}
		Calc();
	}
	void Del(ll y)
	{
		sz--;
		for(int i=1;i<=sz;i++)
		{
			if(x[i]>y) x[i-1]=x[i];
		}
		Calc();
	}
	ll mn(){ return sz?x[0]:inf;}
	ll mx(){ return sz?x[sz-1]:-inf;}
} Block[N/S+5];
int n;
ll a[N],x[N];
void Rebuild()
{
	int i,j;
	for(i=1;i<=n;i++) a[i-1]=x[i];
	sort(a,a+n);
	for(i=0,j=0;i<n;i+=S,j++) Block[j].init(a+i,min(i+S,n)-i);
}
int FindBlock(ll y){ if(Block[0].mn()>y) return 0;for(int i=0,j=0;i<n;i+=S,j++) if(Block[j].mn()<=y && Block[j+1].mn()>y) return j;}
void Del(ll y){ Block[FindBlock(y)].Del(y);}
void Add(ll y){ Block[FindBlock(y)].Add(y);}
int main()
{
	int q,i,j,k,t,p,d;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&x[i]),a[i-1]=x[i];
	sort(a,a+n);
	for(i=0,j=0;i<n;i+=S,j++) Block[j].init(a+i,min(i+S,n)-i);
	scanf("%i",&q);
	for(k=1;k<=q;k++)
	{
		scanf("%i",&t);
		if(k%(S-1)==0) Rebuild();
		if(t==1)
		{
			scanf("%i %i",&p,&d);
			Del(x[p]);
			x[p]+=d;
			Add(x[p]);
		}
		else
		{
			ll l,r;
			scanf("%lld %lld",&l,&r);
			int L=FindBlock(l);
			int R=FindBlock(r);
			ll ans=0;
			if(L==R)
			{
				ll sum=0,sz=0;
				for(i=0;i<Block[L].sz;i++)
				{
					if(Block[L].x[i]>=l && Block[L].x[i]<=r)
					{
						ans+=Block[L].x[i]*sz-sum;
						sum+=Block[L].x[i];
						sz++;
					}
				}
			}
			else
			{
				ll sum=0,sz=0;
				for(i=0;i<Block[L].sz;i++)
				{
					if(Block[L].x[i]>=l)
					{
						ans+=Block[L].x[i]*sz-sum;
						sum+=Block[L].x[i];
						sz++;
					}
				}
				for(i=L+1;i<R;i++)
				{
					ans+=Block[i].sol;
					ans+=Block[i].sum*sz-sum*Block[i].sz;
					sum+=Block[i].sum;
					sz+=Block[i].sz;
				}
				for(i=0;i<Block[R].sz;i++)
				{
					if(Block[R].x[i]<=r)
					{
						ans+=Block[R].x[i]*sz-sum;
						sum+=Block[R].x[i];
						sz++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}