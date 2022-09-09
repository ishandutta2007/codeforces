#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int M=2*N;
int lzy[M],sum[M],ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
//1 - and
//2 - xor
//3 - or
int Compose(int x, int y)
{
	if(x==0) return y;
	if(y==0) return x;
	if(x==1 && y==1) return 1;
	if(x==1 && y==2) return 3;
	if(x==1 && y==3) return 3;
	if(x==2 && y==1) return 1;
	if(x==2 && y==2) return 0;
	if(x==2 && y==3) return 3;
	if(x==3 && y==1) return 1;
	if(x==3 && y==2) return 1;
	if(x==3 && y==3) return 3;
}
void Propagate(int c, int ss, int se)
{
	if(lzy[c]==1)
	{
		sum[c]=0;
		if(ss!=se)
		{
			lzy[ls[c]]=Compose(lzy[ls[c]],lzy[c]);
			lzy[rs[c]]=Compose(lzy[rs[c]],lzy[c]);
		}
	}
	else if(lzy[c]==2)
	{
		sum[c]=se-ss+1-sum[c];
		if(ss!=se)
		{
			lzy[ls[c]]=Compose(lzy[ls[c]],lzy[c]);
			lzy[rs[c]]=Compose(lzy[rs[c]],lzy[c]);
		}
	}
	else if(lzy[c]==3)
	{
		sum[c]=se-ss+1;
		if(ss!=se)
		{
			lzy[ls[c]]=Compose(lzy[ls[c]],lzy[c]);
			lzy[rs[c]]=Compose(lzy[rs[c]],lzy[c]);
		}
	}
	lzy[c]=0;
}
void Set(int c, int ss, int se, int qs, int qe, int op)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		lzy[c]=op;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,op);
	Set(rs[c],mid+1,se,qs,qe,op);
	sum[c]=sum[ls[c]]+sum[rs[c]];
}
int A;
void Get(int c, int ss, int se)
{
	Propagate(c,ss,se);
	if(ss==se){ A=ss;return;}
	int mid=ss+se>>1;
	Propagate(ls[c],ss,mid);
	Propagate(rs[c],mid+1,se);
	if(sum[ls[c]]==mid-ss+1) Get(rs[c],mid+1,se);
	else Get(ls[c],ss,mid);
}
ll l[N],r[N];
int t[N];
vector<ll> id;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %lld %lld",&t[i],&l[i],&r[i]);
		id.pb(l[i]);
		id.pb(r[i]+1);
	}
	id.pb(1);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	Build(root,1,N);
	for(i=1;i<=n;i++)
	{
		l[i]=lower_bound(id.begin(),id.end(),l[i])-id.begin()+1;
		r[i]=upper_bound(id.begin(),id.end(),r[i])-id.begin();
		if(t[i]==1) Set(root,1,N,l[i],r[i],3);
		if(t[i]==2) Set(root,1,N,l[i],r[i],1);
		if(t[i]==3) Set(root,1,N,l[i],r[i],2);
		Get(root,1,N);
		printf("%lld\n",id[A-1]);
	}
	return 0;
}