#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
const int N=100050;
const int M=2*N;
const int S=2154;
map<int,int> id;
int a[N],b[N];
struct Query
{
	int l,r,t,i;
	Query(int a=0, int b=0, int c=0, int d=0){ l=a,r=b,t=c,i=d;}
	bool operator < (Query b)
	{
		if(r/S==b.r/S && l/S==b.l/S) return t<b.t;
		if(r/S==b.r/S) return l<b.l;
		return r<b.r;
	}
} Q[N];
int cnt1[M],cnt2[N];
void Add(int i){ cnt2[cnt1[i]++]--;cnt2[cnt1[i]]++;}
void Del(int i){ cnt2[cnt1[i]--]--;cnt2[cnt1[i]]++;}
int x[N],y[N],p[N],L=1,R,K;
void Upd(int i)
{
	if(p[i]>=L && p[i]<=R) Del(a[p[i]]),Add(x[i]);
	a[p[i]]=x[i];
}
void Err(int i)
{
	if(p[i]>=L && p[i]<=R) Del(a[p[i]]),Add(y[i]);
	a[p[i]]=y[i];
}
int sol[N];
int main()
{
	int n,q,i,t,l,r,m=0,qs=0,cnt=0,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]=(id[a[i]]?id[a[i]]:id[a[i]]=++cnt),b[i]=a[i];
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&l,&r);
			qs++;
			Q[qs]=Query(l,r,m,qs);
		}
		else
		{
			m++;
			scanf("%i %i",&p[m],&x[m]);
			x[m]=(id[x[m]]?id[x[m]]:id[x[m]]=++cnt);
			y[m]=b[p[m]];
			b[p[m]]=x[m];
		}
	}
	sort(Q+1,Q+1+qs);
	for(i=1;i<=qs;i++)
	{
		//printf("%i %i %i %i\n",Q[i].l,Q[i].r,Q[i].t,Q[i].i);
		while(L<Q[i].l) Del(a[L++]);
		while(L>Q[i].l) Add(a[--L]);
		while(R<Q[i].r) Add(a[++R]);
		while(R>Q[i].r) Del(a[R--]);
		while(K<Q[i].t) Upd(++K);
		while(K>Q[i].t) Err(K--);
		for(j=1;j<S;j++) if(!cnt2[j]) break;
		sol[Q[i].i]=j;
	}
	for(i=1;i<=qs;i++) printf("%i\n",sol[i]);
	return 0;
}