#include <stdio.h>
const int N=200050;
const int M=2*N;
struct Gauss
{
	int a[32];
	Gauss(){ for(int i=0;i<32;i++) a[i]=0;}
	void Add(int x)
	{
		for(int i=31;~i;i--)
		{
			if((x>>i)&1)
			{
				if(a[i]) x^=a[i];
				else{ a[i]=x;return;}
			}
			if(x==0) return;
		}
	}
	void Init(){ for(int i=0;i<32;i++) a[i]=0;}
	int Count(){ int ret=0;for(int i=0;i<32;i++) if(a[i]) ret++;return 1<<ret;}
} x[M];
int ls[M],rs[M],a[N],tsz,root;
void upd(int c)
{
	int i;
	for(i=0;i<32;i++) x[c].a[i]=x[ls[c]].a[i];
	for(i=0;i<32;i++) x[c].Add(x[rs[c]].a[i]);
}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		x[c].Add(a[ss]);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	upd(c);
}
void Set(int c, int ss, int se, int qi, int val)
{
	if(qi>se) return;
	if(ss==se)
	{
		x[c].Init();
		x[c].Add(val);
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	upd(c);
}
Gauss Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return Gauss();
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	Gauss ret=Get(ls[c],ss,mid,qs,qe);
	Gauss tmp=Get(rs[c],mid+1,se,qs,qe);
	for(int i=0;i<32;i++) ret.Add(tmp.a[i]);
	return ret;
}
int BIT[N];
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]^=f;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret^=BIT[i];return ret;}
int main()
{
	int n,q,i,l,r,t,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>=1;i--) a[i]^=a[i-1],Set(i,a[i]);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			scanf("%i",&x);r++;
			a[l]^=x;Set(root,1,n,l,a[l]);Set(l,x);
			a[r]^=x;Set(root,1,n,r,a[r]);Set(r,x);
		}
		else
		{
			Gauss sol=Get(root,1,n,l+1,r);
			sol.Add(Get(l));
			printf("%i\n",sol.Count());
		}
	}
	return 0;
}