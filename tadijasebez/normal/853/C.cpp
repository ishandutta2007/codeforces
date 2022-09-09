#include <stdio.h>
const int M=5000000;
const int N=200050;
int x[M],rs[M],ls[M],root[N],clock;
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++clock,x[c]=x[p]+1,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p, int c, int ss, int se, int qs, int qe)
{
	if(qe<qs) return 0;
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[c]-x[p];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)+Get(rs[p],rs[c],mid+1,se,qs,qe);
}
int n;
int Get(int x1, int x2, int y1, int y2)
{
	return Get(root[x1-1],root[x2],1,n,y1,y2);
}
int main()
{
	int i,x,q,l,d,r,u;
	scanf("%i%i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		Set(root[i-1],root[i],1,n,x);
	}
	long long tmp,sq,sol;
	bool ok=false;
	//if(n==7 && q==7) ok=true;
	while(q--)
	{
		scanf("%i %i %i %i",&l,&d,&r,&u);
		sol=0;
		sq=Get(1,l-1,1,d-1);
		tmp=Get(l,n,d,n);
		sol+=sq*tmp;
		if(ok) printf("1:%i %i %i\n",sq,tmp,sol);
		sq=Get(l,r,1,d-1);
		tmp=Get(1,n,d,n);
		sol+=sq*tmp;
		if(ok) printf("2:%i %i %i\n",sq,tmp,sol);
		sq=Get(r+1,n,1,d-1);
		tmp=Get(1,r,d,n);
		sol+=sq*tmp;
		if(ok) printf("3:%i %i %i\n",sq,tmp,sol);
		sq=Get(r+1,n,d,u);
		tmp=Get(1,r,d,n);
		sol+=sq*tmp;
		if(ok) printf("4:%i %i %i\n",sq,tmp,sol);
		sq=Get(r+1,n,u+1,n);
		tmp=Get(1,r,d,u);
		sol+=sq*tmp;
		if(ok) printf("5:%i %i %i\n",sq,tmp,sol);
		sq=Get(l,r,u+1,n);
		tmp=Get(1,r,d,u);
		sol+=sq*tmp;
		if(ok) printf("6:%i %i %i\n",sq,tmp,sol);
		sq=Get(1,l-1,u+1,n);
		tmp=Get(l,r,d,u);
		sol+=sq*tmp;
		if(ok) printf("7:%i %i %i\n",sq,tmp,sol);
		sq=Get(1,l-1,d,u);
		tmp=Get(l,r,d,u);
		sol+=sq*tmp;
		if(ok) printf("8:%i %i %i\n",sq,tmp,sol);
		sol+=tmp*(tmp-1)/2;
		printf("%lld\n",sol);
	}
	return 0;
}