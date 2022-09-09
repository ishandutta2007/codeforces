#include <stdio.h>
int SegmentTree[200000];
int Lazy[200000];
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
void BuildSegmentTree(int ss, int se, int si, int a[])
{
	Lazy[si]=0;
	if(ss==se)
	{
		SegmentTree[si]=a[ss];
		return;
	}
	int mid=(ss+se)>>1;
	BuildSegmentTree(ss,mid,si*2,a);
	BuildSegmentTree(mid+1,se,si*2+1,a);
	SegmentTree[si]=max(SegmentTree[si*2],SegmentTree[si*2+1]);
}
void Set(int ss, int se, int si, int qs, int qe)
{
	if(Lazy[si]>0)
	{
		SegmentTree[si]+=Lazy[si];
		if(ss!=se)
		{
			Lazy[si*2]+=Lazy[si];
			Lazy[si*2+1]+=Lazy[si];
		}
		Lazy[si]=0;
	}
	if(se<qs || ss>qe) return;
	if(ss>=qs && se<=qe)
	{
		SegmentTree[si]++;
		if(ss!=se)
		{
			Lazy[si*2]++;
			Lazy[si*2+1]++;
		}
		return;
	}
	int mid=(ss+se)>>1;
	Set(ss,mid,si*2,qs,qe);
	Set(mid+1,se,si*2+1,qs,qe);
	SegmentTree[si]=max(SegmentTree[si*2],SegmentTree[si*2+1]);
}
int Get(int ss, int se, int si, int qs, int qe)
{
	if(Lazy[si]>0)
	{
		SegmentTree[si]+=Lazy[si];
		if(ss!=se)
		{
			Lazy[si*2]+=Lazy[si];
			Lazy[si*2+1]+=Lazy[si];
		}
		Lazy[si]=0;
	}
	if(se<qs || ss>qe) return 0;
	if(ss>=qs && se<=qe) return SegmentTree[si];
	int mid=(ss+se)>>1;
	return max(Get(ss,mid,si*2,qs,qe),Get(mid+1,se,si*2+1,qs,qe));
}
int DP[35050];
int Prev[35050];
int Now[35050];
int a[35050];
bool visited[35050];
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=0;i<n;i++) Now[i]=-1;
	for(i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
		Prev[i]=Now[a[i]];
		Now[a[i]]=i;
	}
	//for(i=0;i<n;i++) printf("%i ",Prev[i]);
	//printf("\n");
	DP[0]=1;
	visited[a[0]]=true;
	for(i=1;i<n;i++)
	{
		DP[i]=DP[i-1];
		if(!visited[a[i]])
		{
			visited[a[i]]=true;
			DP[i]++;
		}
	}
	for(j=1;j<k;j++)
	{
		BuildSegmentTree(0,n-1,1,DP);
		for(i=0;i<j;i++) DP[i]=0;
		for(i=j;i<n;i++)
		{
			Set(0,n-1,1,max(0,Prev[i]),i-1);
			DP[i]=Get(0,n-1,1,0,i-1);
		}
	}
	printf("%i\n",DP[n-1]);
	return 0;
}