#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
typedef struct S
{
	u val,ki,ka,min,max;llu sum;
	struct S *lc,*rc;
}v;
v*alloc(u ki,u ka,u val)
{
	v*x;
	x=(v*)malloc(sizeof(v));
	x->val=val;
	x->min=val;
	x->max=val;
	x->ki=ki;
	x->ka=ka;
	x->sum=(ka-ki+1)*(llu)val;
	x->lc=x->rc=NULL;
	return x;
}
llu que(v *x,u lo,u hi)
{
	if(hi<x->ki||lo>x->ka)return 0;
	if(lo<=x->ki&&hi>=x->ka)return x->sum;
	u ll,rr;
	if(x->val)
	{
		ll=lo<x->ki?x->ki:lo;
		rr=hi>x->ka?x->ka:hi;
		if(rr<ll)return 0;
		return(rr-ll+1)*(llu)x->val;
	}
	llu a=que(x->lc,lo,hi)+que(x->rc,lo,hi);
	return a;
}
void set(v *x,u lo,u hi,u val)
{
	if(hi<x->ki||lo>x->ka||x->min>=val)
	{
		return;
	}
	if(lo<=x->ki&&hi>=x->ka&&x->max<=val)
	{
		x->val=x->min=x->max=val;
		x->sum=val*(llu)(x->ka-x->ki+1);
		return;
	}
	u m;
	if(x->val)
	{
		if(val<=x->val)return;
		m=(x->ki+x->ka)>>1;
		if(!x->lc)x->lc=alloc(x->ki,m,x->val);
		else
		{
			x->lc->val=x->lc->min=x->lc->max=x->val;
			x->lc->sum=(m-x->ki+1)*(llu)x->val;
		}
		if(!x->rc)x->rc=alloc(m+1,x->ka,x->val);
		else
		{
			x->rc->val=x->rc->min=x->rc->max=x->val;
			x->rc->sum=(x->ka-m)*(llu)x->val;
		}
		x->val=0;
	}
	set(x->lc,lo,hi,val);
	set(x->rc,lo,hi,val);
	if(x->lc->val&&x->lc->val==x->rc->val)
	{
		x->val=x->lc->val;
		x->sum=x->val*(llu)(x->ka-x->ki+1);
	}
	else x->sum=x->lc->sum+x->rc->sum;
	x->min=x->lc->min;
	x->max=x->rc->max;
	return;
}
v *p;
u A[222222],F[222222],G[222222];
int main()
{
	u n,h,i,j,k,x;llu r;
	scanf("%u",&n);
	p=alloc(0,n,1);
	for(i=0;++i<=n;A[i]=x)
	{
		scanf("%u",&x);h=0;
		for(j=1;j*j<=x;++j)if(x%j==0)
		{
			if(!F[j])F[j]=i;
			else if(h<j)h=j;
			if(j!=(k=x/j))
			{
				if(!F[k])F[k]=i;
				else if(h<k)h=k;
			}
		}
		set(p,i,n-1,h);
	}
	r=que(p,2,n-1);
	for(i=n;i>1;--i)
	{
		x=A[i];h=0;
		for(j=1;j*j<=x;++j)if(x%j==0)
		{
			if(!G[j])G[j]=i;
			else if(h<j)h=j;
			if(j!=(k=x/j))
			{
				if(!G[k])G[k]=i;
				else if(h<k)h=k;
			}
		}
		set(p,0,i-1,h);
		for(x=A[i],j=1;j*j<=x;++j)if(x%j==0)
		{
			if(F[j]&&F[j]<i)set(p,F[j],i-1,j);
			if(F[k=x/j]&&F[k]<i)set(p,F[k],i-1,k);
		}
		r+=que(p,i==n?1:0,i-2);
	}
	printf("%I64u\n",r);
	return 0;
}