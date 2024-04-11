#include <stdio.h>
const int N=200050;
const int M=4*N;
int x[M],ls[M],rs[M],clock,root1,root2,a[N];
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock,x[c]=qi;
	if(a[x[c]]<a[qi]) x[c]=qi;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	int u=Get(ls[c],ss,mid,qs,qe);
	int v=Get(rs[c],mid+1,se,qs,qe);
	if(!u) return v;
	if(!v) return u;
	if(a[u]>a[v]) return u;
	return v;
}
void Set1(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock,x[c]=qi;
	if(a[x[c]]>a[qi]) x[c]=qi;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set1(ls[c],ss,mid,qi);
	else Set1(rs[c],mid+1,se,qi);
}
int Get1(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	int u=Get1(ls[c],ss,mid,qs,qe);
	int v=Get1(rs[c],mid+1,se,qs,qe);
	if(!u) return v;
	if(!v) return u;
	if(a[u]<a[v]) return u;
	return v;
}
int main()
{
	int n,q,i,l,r,k;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Set(root1,1,n,i),Set1(root2,1,n,i);
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		int u=Get(root1,1,n,l,r);
		if(a[u]==k)
		{
			u=Get1(root2,1,n,l,r);
			if(a[u]==k) printf("-1\n");
			else printf("%i\n",u);
		}
		else printf("%i\n",u);
	}
	return 0;
}