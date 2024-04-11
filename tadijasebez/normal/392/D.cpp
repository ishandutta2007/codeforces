#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
//Segment Tree Beats
int ls[M],rs[M],fmn[M],smn[M],fsl[M],ssl[M],lzy[M],root,tsz;
void Build(int &c, int ss, int se)
{
	c=++tsz;fmn[c]=0;smn[c]=inf;fsl[c]=ss;ssl[c]=inf;lzy[c]=-inf;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Upd(int c, int x)
{
	if(smn[c]>x && fmn[c]<x)
	{
		fsl[c]+=x-fmn[c];
		fmn[c]=x;
		lzy[c]=x;
	}
}
void Push(int c){ Upd(ls[c],lzy[c]);Upd(rs[c],lzy[c]);lzy[c]=-inf;}
void Set(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe || fmn[c]>=x) return;
	if(qs<=ss && qe>=se && smn[c]>x) return Upd(c,x);
	int mid=ss+se>>1;
	Push(c);
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	if(fmn[ls[c]]==fmn[rs[c]])
	{
		fmn[c]=fmn[ls[c]];
		fsl[c]=min(fsl[ls[c]],fsl[rs[c]]);
		smn[c]=min(smn[ls[c]],smn[rs[c]]);
		ssl[c]=min(ssl[ls[c]],ssl[rs[c]]);
	}
	else if(fmn[ls[c]]<fmn[rs[c]])
	{
		fmn[c]=fmn[ls[c]];
		fsl[c]=fsl[ls[c]];
		smn[c]=min(smn[ls[c]],fmn[rs[c]]);
		ssl[c]=min(ssl[ls[c]],min(fsl[rs[c]],ssl[rs[c]]));
	}
	else
	{
		fmn[c]=fmn[rs[c]];
		fsl[c]=fsl[rs[c]];
		smn[c]=min(smn[rs[c]],fmn[ls[c]]);
		ssl[c]=min(ssl[rs[c]],min(fsl[ls[c]],ssl[ls[c]]));
	}
}
int a[N],b[N],c[N],n;
map<int,int> mn[3];
vector<int> all;
void Add(int x)
{
	//printf("Add: %i\n",x);
	if(!mn[1].count(x) && !mn[2].count(x)) Set(root,0,n,0,n,inf-1);
	else if(!mn[1].count(x)) Set(root,0,n,0,n,mn[2][x]);
	else if(!mn[2].count(x)) Set(root,0,n,0,mn[1][x]-1,inf-1);
	else Set(root,0,n,0,mn[1][x]-1,mn[2][x]);
}
int main()
{
	int i;
	scanf("%i",&n);
	Build(root,0,n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);all.push_back(a[i]);
		if(!mn[0].count(a[i])) mn[0][a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%i",&b[i]);all.push_back(b[i]);
		if(!mn[1].count(b[i])) mn[1][b[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%i",&c[i]);all.push_back(c[i]);
		if(!mn[2].count(c[i])) mn[2][c[i]]=i;
	}
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(i:all) if(!mn[0].count(i)) Add(i);
	int ans=3*n;
	for(i=n;i>=0;i--)
	{
		ans=min(ans,min(fsl[root],ssl[root])+i);
		//printf("i:%i sl:%i\n",i,min(fsl[root],ssl[root]));
		if(i>0 && mn[0][a[i]]==i) Add(a[i]);
	}
	printf("%i\n",ans);
	return 0;
}