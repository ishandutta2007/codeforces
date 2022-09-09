#include <stdio.h>
struct Copy
{
	int id,x,y,k;
	Copy(){}
	Copy(int i, int a, int b, int c){ id=i,x=a,y=b,k=c;}
	inline Copy operator + (const Copy &b) const
	{
		if(id>b.id) return *this;
		else return b;
	}
};
const int N=100050;
const int M=N*2;
Copy x[M];
int ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qs, int qe, Copy val)
{
	if(!c) c=++clock;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		x[c]=x[c]+val;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
Copy Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return x[c]+Get(ls[c],ss,mid,qi);
	else return x[c]+Get(rs[c],mid+1,se,qi);
}
int A[N],B[N];
int main()
{
	int n,q,i,t,x,y,k;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	for(i=1;i<=n;i++) scanf("%i",&B[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&x,&y,&k);
			Set(root,1,N,y,y+k-1,Copy(i,x,y,k));
		}
		else
		{
			scanf("%i",&x);
			Copy tmp=Get(root,1,N,x);
			if(tmp.id==0) printf("%i\n",B[x]);
			else
			{
				y=tmp.x+(x-tmp.y);
				printf("%i\n",A[y]);
			}
		}
	}
	return 0;
}