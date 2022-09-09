#include <stdio.h>
const int N=200050;
const int L=-N;
const int R=N;
const int M=4*N;
int x[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	x[c]+=f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int a[N],b[N],id[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&b[i]),id[b[i]]=i;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Set(root,L,R,id[a[i]]-i,1);
	for(i=1;i<=n;i++)
	{
		int top=n,bot=0,mid,ans;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(root,L,R,-i+1-mid,-i+1+mid)>0) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		printf("%i\n",ans);
		Set(root,L,R,id[a[i]]-i,-1);
		Set(root,L,R,id[a[i]]-i-n,1);
	}
	return 0;
}