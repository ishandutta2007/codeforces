#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int M=2*N;
const int mod=1e9+7;
int pow(int x, int k){ int ret=1;while(k--) ret=(ll)ret*x%mod;return ret;}
void ck(int &x){ while(x>=mod) x-=mod;while(x<0) x+=mod;}
int pre[N][6];
struct Node
{
	int sum[6],lzy,l,r;
	Node(){}
	void init(int x){ for(int i=0;i<6;i++) sum[i]=(ll)x*(pre[r][i]-pre[l-1][i])%mod,ck(sum[i]);}
} node[M];
Node operator + (Node a, Node b)
{
	Node ans;ans.lzy=-1;
	ans.l=a.l;ans.r=b.r;
	for(int i=0;i<6;i++) ans.sum[i]=a.sum[i]+b.sum[i],ck(ans.sum[i]);
	return ans;
}
int ls[M],rs[M],tsz,root,a[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c].l=node[c].r=ss;node[c].lzy=-1;node[c].init(a[ss]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Push(int c, int ss, int se)
{
	if(node[c].lzy==-1) return;
	if(ss!=se)
	{
		node[ls[c]].init(node[c].lzy);node[ls[c]].lzy=node[c].lzy;
		node[rs[c]].init(node[c].lzy);node[rs[c]].lzy=node[c].lzy;
	}
	node[c].lzy=-1;
}
void Set(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ node[c].init(x);node[c].lzy=x;return;}
	Push(c,ss,se);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	Push(c,ss,se);
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,i,j,q,l,r,x,k;char t;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) for(j=0;j<6;j++) pre[i][j]=pre[i-1][j]+pow(i,j),ck(pre[i][j]);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	while(q--)
	{
		scanf("\n%c %i %i",&t,&l,&r);
		if(t=='=')
		{
			scanf("%i",&x);
			Set(root,1,n,l,r,x);
		}
		else
		{
			scanf("%i",&k);
			Node tmp=Get(root,1,n,l,r);
			int ans=0;
			l--;
			if(k==0)
			{
				ans=tmp.sum[0];
			}
			else if(k==1)
			{
				ans=tmp.sum[1]-(ll)l*tmp.sum[0]%mod;
				ck(ans);
			}
			else if(k==2)
			{
				ans=(ll)tmp.sum[0]*l%mod*l%mod;
				ans+=tmp.sum[2];ck(ans);
				ans-=(ll)2*l%mod*tmp.sum[1]%mod;ck(ans);
			}
			else if(k==3)
			{
				ans=tmp.sum[3];
				ans-=(ll)3*tmp.sum[2]%mod*l%mod;ck(ans);
				ans+=(ll)3*tmp.sum[1]%mod*l%mod*l%mod;ck(ans);
				ans-=(ll)l*l%mod*l%mod*tmp.sum[0]%mod;ck(ans);
			}
			else if(k==4)
			{
				ans=tmp.sum[4];
				ans-=(ll)4*tmp.sum[3]%mod*l%mod;ck(ans);
				ans+=(ll)6*tmp.sum[2]%mod*l%mod*l%mod;ck(ans);
				ans-=(ll)4*tmp.sum[1]%mod*l%mod*l%mod*l%mod;ck(ans);
				ans+=(ll)tmp.sum[0]*l%mod*l%mod*l%mod*l%mod;ck(ans);
			}
			else if(k==5)
			{
				ans=tmp.sum[5];
				ans-=(ll)5*tmp.sum[4]%mod*l%mod;ck(ans);
				ans+=(ll)10*tmp.sum[3]%mod*l%mod*l%mod;ck(ans);
				ans-=(ll)10*tmp.sum[2]%mod*l%mod*l%mod*l%mod;ck(ans);
				ans+=(ll)5*tmp.sum[1]%mod*l%mod*l%mod*l%mod*l%mod;ck(ans);
				ans-=(ll)tmp.sum[0]*l%mod*l%mod*l%mod*l%mod*l%mod;ck(ans);
			}
			printf("%i\n",ans);
		}
	}
	return 0;
}