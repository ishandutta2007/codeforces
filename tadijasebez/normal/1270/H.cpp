#include <bits/stdc++.h>
using namespace std;
const int N=500050;
const int lim=2*N;
const int M=2*lim+1;
int ls[M],rs[M],tsz,root,mn[M],cnt[M],lzy[M];
void pull(int c)
{
	if(!cnt[ls[c]]) mn[c]=mn[rs[c]],cnt[c]=cnt[rs[c]];
	else if(!cnt[rs[c]]) mn[c]=mn[ls[c]],cnt[c]=cnt[ls[c]];
	else mn[c]=min(mn[ls[c]],mn[rs[c]]),cnt[c]=(mn[c]==mn[ls[c]]?cnt[ls[c]]:0)+(mn[c]==mn[rs[c]]?cnt[rs[c]]:0);
}
void upd(int c, int x){ mn[c]+=x;lzy[c]+=x;}
void push(int c){ if(lzy[c]) upd(ls[c],lzy[c]),upd(rs[c],lzy[c]),lzy[c]=0;}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ upd(c,x);return;}
	push(c);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	pull(c);
}
void Set(int c, int ss, int se, int qi, int x)
{
	if(ss==se){ cnt[c]=x;return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	pull(c);
}
int a[N];
map<int,int> mpp;
void Add(int i, int f){ Add(root,0,lim,min(a[i],a[i+1])+1,max(a[i],a[i+1]),f);}
int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	a[0]=lim;a[n+1]=0;
	Build(root,0,lim);
	for(int i=1;i<=n;i++) Set(root,0,lim,a[i],1),mpp[a[i]]++;
	for(int i=0;i<=n;i++) Add(i,1);
	while(q--)
	{
		int i,x;
		scanf("%i %i",&i,&x);
		Add(i-1,-1);
		Add(i,-1);
		mpp[a[i]]--;
		if(mpp[a[i]]==0) Set(root,0,lim,a[i],0);
		a[i]=x;
		mpp[x]++;
		if(mpp[x]==1) Set(root,0,lim,x,1);
		Add(i-1,1);
		Add(i,1);
		printf("%i\n",cnt[root]);
	}
	return 0;
}