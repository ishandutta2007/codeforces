#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll mx[M],lzy[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;mx[c]=lzy[c]=0;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Push(int c, int ss, int se)
{
	if(!lzy[c]) return;
	if(ss!=se)
	{
		mx[ls[c]]+=lzy[c];lzy[ls[c]]+=lzy[c];
		mx[rs[c]]+=lzy[c];lzy[rs[c]]+=lzy[c];
	}
	lzy[c]=0;
}
void Add(int c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>se || ss>qe || qs>qe) return;
	if(qs<=ss && qe>=se){ mx[c]+=f;lzy[c]+=f;return;}
	Push(c,ss,se);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
int Search(int c, int ss, int se)
{
	if(mx[c]<0) return 0;
	if(ss==se) return mx[c]==0?ss:0;
	int mid=ss+se>>1;
	Push(c,ss,se);
	int x=Search(ls[c],ss,mid);
	if(!x) x=Search(rs[c],mid+1,se);
	return x;
}
int a[N];
int main()
{
	int n,i,q,x;
	scanf("%i %i",&n,&q);Build(root,1,n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Add(root,1,n,i,i,a[i]),Add(root,1,n,i+1,n,-a[i]);
	while(q--)
	{
		scanf("%i %i",&i,&x);
		Add(root,1,n,i,i,x-a[i]);
		Add(root,1,n,i+1,n,a[i]-x);
		int ans=Search(root,1,n);
		if(ans) printf("%i\n",ans);
		else printf("-1\n");
		a[i]=x;
	}
	return 0;
}