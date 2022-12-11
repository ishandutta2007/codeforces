#include <bits/stdc++.h>
#define Maxn 10007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,q,lx,rx,val,cnt;
bitset<Maxn> ans;
vector<int> p[40007];
void insert(int node,int L,int R)
{
	if (L>rx||R<lx) return;
	if (L>=lx&&R<=rx)
	{
		p[node].push_back(val);
		return;
	}
	int mid=(L+R)/2;
	insert(node*2,L,mid);
	insert(node*2+1,mid+1,R);
}
void query(int node,int L,int R,bitset<Maxn> now)
{
	for (int i=0;i<(int)p[node].size();i++)
		now|=now<<p[node][i];
	if (L==R)
	{
		ans|=now;
		return;
	}
	int mid=(L+R)/2;
	query(node*2,L,mid,now);
	query(node*2+1,mid+1,R,now);
}
int main()
{
	n=read(),q=read();
	for (int i=1;i<=q;i++)
	{
		lx=read(),rx=read(),val=read();
		insert(1,1,n);
	}
	query(1,1,n,bitset<Maxn>(1));
	for (int i=1;i<=n;i++)
		if (ans[i]) ++cnt;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
		if (ans[i]) printf("%d ",i);
	printf("\n");
	return 0;
}