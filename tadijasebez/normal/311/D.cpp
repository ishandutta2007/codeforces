#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=95542721;
const int N=100050;
const int M=2*N;
const int H=48;
void ck(int &x){ while(x>=mod) x-=mod;}
int tmp[H];
void Shift(int a[], int lzy)
{
	for(int i=0;i<H;i++) tmp[(i+H-lzy)%H]=a[i];
	for(int i=0;i<H;i++) a[i]=tmp[i];
}
struct Node
{
	int sum[H],lzy;
	Node(){}
	void init(int x)
	{
		sum[0]=x;
		for(int i=1;i<H;i++) sum[i]=(ll)sum[i-1]*sum[i-1]%mod*sum[i-1]%mod;
	}
} node[M];
Node operator + (Node a, Node b)
{
	Node ans;ans.lzy=0;
	for(int i=0;i<H;i++) ans.sum[i]=a.sum[i]+b.sum[i],ck(ans.sum[i]);
	return ans;
}
int ls[M],rs[M],tsz,root,a[N];
void Push(int c, int ss, int se)
{
	node[c].lzy%=H;
    if(!node[c].lzy) return;
    if(ss!=se)
	{
		node[ls[c]].lzy+=node[c].lzy;
		node[ls[c]].lzy%=H;
		Shift(node[ls[c]].sum,node[c].lzy);
		node[rs[c]].lzy+=node[c].lzy;
		node[rs[c]].lzy%=H;
		Shift(node[rs[c]].sum,node[c].lzy);
	}
	node[c].lzy=0;
}
void Build(int &c, int ss, int se)
{
	c=++tsz;node[c].lzy=0;
	if(ss==se){ node[c].init(a[ss]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ Shift(node[c].sum,1);node[c].lzy+=1;return;}
	Push(c,ss,se);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	node[c]=node[ls[c]]+node[rs[c]];
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return node[c].sum[0];
	Push(c,ss,se);
	int mid=ss+se>>1;
	int ans=Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	ck(ans);return ans;
}
int main()
{
	int n,q,i,t,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),ck(a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1) printf("%i\n",Get(root,1,n,l,r));
		else Set(root,1,n,l,r);
	}
	return 0;
}