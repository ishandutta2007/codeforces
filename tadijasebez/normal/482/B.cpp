#include <stdio.h>
const int N=100050;
int SegmentTree[2][N<<2];
void Set(int ss, int se, int si, int qs, int qe, int val)
{
	if(qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		SegmentTree[0][si]|=val;
		return;
	}
	int mid=ss+se>>1;
	Set(ss,mid,si*2,qs,qe,val);
	Set(mid+1,se,si*2+1,qs,qe,val);
}
int A;
void Get(int ss, int se, int si, int qi)
{
	A|=SegmentTree[0][si];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ss,mid,si*2,qi);
	else Get(mid+1,se,si*2+1,qi);
}
int a[N];
void BuildSegmentTree(int ss, int se, int si)
{
	if(ss==se)
	{
		SegmentTree[1][si]=a[ss];
		return;
	}
	int mid=ss+se>>1;
	BuildSegmentTree(ss,mid,si*2);
	BuildSegmentTree(mid+1,se,si*2+1);
	SegmentTree[1][si]=SegmentTree[1][si*2]&SegmentTree[1][si*2+1];
}
int Query(int ss, int se, int si, int qs, int qe)
{
	if(qe<ss || se<qs) return (1<<31)-1;
	if(qs<=ss && qe>=se) return SegmentTree[1][si];
	int mid=ss+se>>1;
	return Query(ss,mid,si*2,qs,qe)&Query(mid+1,se,si*2+1,qs,qe);
}
int l[N],r[N],v[N];
int main()
{
	int n,q,i;
	scanf("%i %i",&n,&q);
	for(i=0;i<q;i++)
	{
		scanf("%i %i %i",&l[i],&r[i],&v[i]);
		Set(1,n,1,l[i],r[i],v[i]);
	}
	for(i=1;i<=n;i++)
	{
		A=0;
		Get(1,n,1,i);
		a[i]=A;
	}
	BuildSegmentTree(1,n,1);
	bool ok=true;
	for(i=0;i<q;i++)
	{
		if(v[i]!=Query(1,n,1,l[i],r[i])) ok=false;
	}
	if(ok)
	{
		printf("YES\n");
		for(i=1;i<=n;i++) printf("%i ",a[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}