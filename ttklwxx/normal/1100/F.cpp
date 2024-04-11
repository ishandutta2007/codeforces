#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int xx[500005][31];
vector<int>v[2000005];
int ql[500005],qr[500005],qans[500005];
int a[500005];
inline void insert(int bh,int x)
{
	for(int i=20;i>=0;i--)
	{
		if((x&(1<<i))==0)continue;
		if(xx[bh][i]==0)
		{
			xx[bh][i]=x;
			return;
		}
		x^=xx[bh][i];
	}
}
int yy[31];
inline void ainsert(int x)
{
	for(int i=20;i>=0;i--)
	{
		if((x&(1<<i))==0)continue;
		if(yy[i]==0)
		{
			yy[i]=x;
			return;
		}
		x^=yy[i];
	}
}
inline int findans(int l,int r)
{
	for(int i=0;i<=20;i++)yy[i]=xx[l][i];
	for(int i=20;i>=0;i--)if(xx[r][i]!=0)
	{
		ainsert(xx[r][i]);
	}
	int ans=0;
	for(int i=20;i>=0;i--)if((ans^yy[i])>ans)ans^=yy[i];
	return ans;
}
void dfs(int l,int r,int bh)
{
	if(l>r)return;
	int mid=(l+r)>>1;
	for(int j=0;j<=20;j++)xx[mid][j]=0;
	insert(mid,a[mid]);
	for(int i=mid-1;i>=l;i--)
	{
		for(int j=0;j<=20;j++)xx[i][j]=xx[i+1][j];
		insert(i,a[i]);
	}
	for(int i=mid+1;i<=r;i++)
	{
		for(int j=0;j<=20;j++)xx[i][j]=xx[i-1][j];
		insert(i,a[i]);
	}
	for(int i=0;i<v[bh].size();i++)
	{
		if(qr[v[bh][i]]<mid)v[bh<<1].push_back(v[bh][i]);
		else if(ql[v[bh][i]]>mid)v[bh<<1|1].push_back(v[bh][i]);
		else
		{
			qans[v[bh][i]]=findans(ql[v[bh][i]],qr[v[bh][i]]);
		}
	}
	dfs(l,mid-1,bh<<1);
	dfs(mid+1,r,bh<<1|1);
}
int main()
{
	int n,q,l,r;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	q=read();
	for(int i=1;i<=q;i++)
	{
		ql[i]=read();
		qr[i]=read();
		v[1].push_back(i);
	}
	//printf("fdoipsjoisdjgifposghiodhbj cvnv\n");
	dfs(1,n,1);
	for(int i=1;i<=q;i++)printf("%d\n",qans[i]);
	return 0;
}