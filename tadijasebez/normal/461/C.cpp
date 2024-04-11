#include <stdio.h>
const int N=100050;
const int M=2*N;
int x[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int a[N];
int main()
{
	int n,q,t,l,r,p,L,R,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) a[i]=1,Set(root,1,n,i,1);
	L=1;R=n;
	bool flip=0;
	while(q--)
	{
		scanf("%i",&t);
		if(t==2)
		{
			scanf("%i %i",&l,&r);
			int len=r-l;
			if(!flip) printf("%i\n",Get(root,1,n,L+l,L+l+len-1));
			else printf("%i\n",Get(root,1,n,R-l-len+1,R-l));
		}
		else
		{
			scanf("%i",&p);
			int len=R-L+1;
			if(flip) p=len-p;
			if(p<len-p)
			{
				for(i=0;i<p;i++)
				{
					a[L+2*p-i-1]+=a[L+i];
					Set(root,1,n,L+2*p-i-1,a[L+i]);
					Set(root,1,n,L+i,0);
					a[L+i]=0;
				}
				L+=p;
				if(flip) flip=0;
			}
			else
			{
				p=len-p;
				for(i=0;i<p;i++)
				{
					a[R-2*p+i+1]+=a[R-i];
					Set(root,1,n,R-2*p+i+1,a[R-i]);
					Set(root,1,n,R-i,0);
					a[R-i]=0;
				}
				R-=p;
				if(!flip) flip=1;
			}
		}
	}
	return 0;
}