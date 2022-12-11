#include<bits/stdc++.h>
using namespace std;
struct Matrix
{
	int v[2][2];
	inline Matrix() {}
	inline Matrix(int a,int b,int c,int d)
	{
		v[0][0]=a,v[0][1]=b,v[1][0]=c,v[1][1]=d;
	}
};
const Matrix base[2]={Matrix(3,0,1,2),Matrix(1,2,1,2)};
const int mod=998244353;
inline Matrix operator * (const Matrix &a,const Matrix &b)
{
	Matrix res;
	for(int i=0;i<=1;++i)
		for(int j=0;j<=1;++j)
		{
			res.v[i][j]=0;
			for(int k=0;k<=1;++k)
				res.v[i][j]=(res.v[i][j]+1ll*a.v[i][k]*b.v[k][j])%mod;
		}
	return res;
}
const int max_n=3e5+5;
Matrix M[max_n];
namespace SegTree
{
	Matrix node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			node[p]=M[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		node[p]=node[ls(p)]*node[rs(p)];
	}
	void modify(int p,int l,int r,int k)
	{
		if(l==r)
		{
			node[p]=M[l];
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(ls(p),l,mid,k);
		else
			modify(rs(p),mid+1,r,k);
		node[p]=node[ls(p)]*node[rs(p)];
	}
}
using namespace SegTree;
int l[max_n],r[max_n];
const int max_R=3e5+5;
vector<int> id[max_R];
int main()
{
	int n;
	scanf("%d",&n);
	M[1]=Matrix(1,0,0,0);
	for(int i=2;i<=n;++i)
		M[i]=base[0];
	build(1,1,n);
	int R=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",l+i,r+i);
		id[l[i]].push_back(i);
		id[r[i]+1].push_back(i);
		R=max(R,r[i]);
	}
	int ans=0;
	for(int i=0;i<=R;++i)
	{
		for(int x:id[i])
		{
			if(l[x]==i)
				M[x]=(x==1?Matrix(0,1,0,0):base[1]);
			else
				M[x]=(x==1?Matrix(1,0,0,0):base[0]);
			modify(1,1,n,x);
		}
		ans+=node[1].v[0][1];
		ans-=ans>=mod?mod:0;
	}
	printf("%d\n",ans);
	return 0;
}