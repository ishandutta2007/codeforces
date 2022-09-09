#include <stdio.h>
#define ll long long
const int N=100050;
const int M=N*2;
const int inf=1e9+7;
int nod[2][M],lzy[2][M],cnt[2][M],sec[2][M],ls[M],rs[M],clock,root;
ll sum[2][M];
void Build(int &c, int ss, int se)
{
	c=++clock;
	for(int i=0;i<2;i++)
	{
		sum[i][c]=cnt[i][c]=0;
		nod[i][c]=lzy[i][c]=sec[i][c]=inf;
	}
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
bool Cut(int c, int w, int k)
{
	if(w<=sec[k][c]) return false;
	if(w<nod[k][c])
	{
		sum[k][c]-=(ll)(nod[k][c]-w)*cnt[k][c];
		nod[k][c]=lzy[k][c]=w;
	}
	return true;
}
int max(int a, int b){ return a>b?a:b;}
void Take(int c)
{
	for(int i=0;i<2;i++)
	{
		nod[i][c]=max(nod[i][ls[c]],nod[i][rs[c]]);
		sum[i][c]=sum[i][ls[c]]+sum[i][rs[c]];
		if(nod[i][ls[c]]==nod[i][rs[c]])
		{
			sec[i][c]=max(sec[i][ls[c]],sec[i][rs[c]]);
			cnt[i][c]=cnt[i][ls[c]]+cnt[i][rs[c]];
		}
		else if(nod[i][ls[c]]<nod[i][rs[c]])
		{
			sec[i][c]=max(nod[i][ls[c]],sec[i][rs[c]]);
			cnt[i][c]=cnt[i][rs[c]];
		}
		else
		{
			sec[i][c]=max(nod[i][rs[c]],sec[i][ls[c]]);
			cnt[i][c]=cnt[i][ls[c]];
		}
	}
}
void Propagate(int c)
{
	for(int i=0;i<2;i++)
	{
		if(lzy[i][c]!=inf)
		{
			Cut(ls[c],lzy[i][c],i);
			Cut(rs[c],lzy[i][c],i);
			lzy[i][c]=inf;
		}
	}
}
void Set(int c, int ss, int se, int qs, int qe, int w, int k)
{
	if(ss>qe || qs>se) return;
	if(w>=nod[k][c]) return;
	if(ss==se)
	{
		nod[k][c]=w;
		sec[k][c]=-inf;
		if(nod[k^1][c]!=inf)
		{
			sum[k][c]=w;
			cnt[k][c]=1;
			sum[k^1][c]=nod[k^1][c];
			cnt[k^1][c]=1;
		}
		return;
	}
	if(qs<=ss && qe>=se && Cut(c,w,k)) return;
	Propagate(c);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,w,k);
	Set(rs[c],mid+1,se,qs,qe,w,k);
	Take(c);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return sum[0][c]+sum[1][c];
	Propagate(c);
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	Build(root,1,N);
	int q,l,r,t,x;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		r--;
		if(t==1)
		{
			scanf("%i",&x);
			if(x>0) Set(root,1,N,l,r,x,0);
			else Set(root,1,N,l,r,-x,1);
		}
		else printf("%lld\n",Get(root,1,N,l,r));
	}
	return 0;
}