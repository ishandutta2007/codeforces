#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include<set>
#include<algorithm>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define LL long long
#define md double
#define RG register
using namespace std;
const int inf=2147483647;
const int N=5e5;
inline int gi() {
	RG int w=0;
	RG bool q=1;
	RG char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int n;
int map[N][11];
int id[41];
struct Node{
	int fa[41];
	int C;
	inline int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
	inline void init(int l) {
		fa[1]=1;C=1;
		for (int i=2;i<=n;i++)
			if (map[l][i]==map[l][i-1]) fa[i]=i-1;
			else fa[i]=i,C++;
		for (int i=1;i<=n;i++) fa[i+n]=fa[i];
	}
	inline void merge(Node *L,Node *R,int mid) {
		int i;C=L->C+R->C;
		for (i=n<<1;i;i--) fa[i]=L->fa[i],fa[i+n*2]=R->fa[i]+n*2;
		for (i=1;i<=n;i++) if (map[mid][i]==map[mid+1][i]&&find(i+n)!=find(i+n*2)) {
				fa[find(i+n)]=find(i+n*2);
				C--;
			}
		for (i=n<<2;i;i--) find(i),id[i]=0;
		for (i=1;i<=n;i++) if (!id[fa[i]]) id[fa[i]]=i,fa[i]=i; else fa[i]=id[fa[i]];
		for (i=n*2;i>n;i--) if (!id[fa[i+n*2]]) id[fa[i+n*2]]=i,fa[i]=i; else fa[i]=id[fa[i+n*2]];
	}
}node[N],ans,o;
inline void build(int i,int l,int r) {
	if (l==r) { node[i].init(l); return; }
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	node[i].merge(&node[i<<1],&node[i<<1|1],mid);
}
inline void query(int i,int l,int r,int L,int R) {
	if (L<=l&&r<=R) {
		if (L==l) ans=node[i];
		else o=ans,ans.merge(&o,&node[i],l-1);
	} else {
		int mid=(l+r)>>1;
		if (L<=mid) query(i<<1,l,mid,L,R);
		if (mid<R) query(i<<1|1,mid+1,r,L,R);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("dface.in","r",stdin);
	freopen("dface.out","w",stdout);
#endif
	n=gi();int m=gi(),Q=gi(),i,j,l,r;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			map[j][i]=gi();
	build(1,1,m);
	while (Q--) {
		l=gi(),r=gi();
		query(1,1,m,l,r);
		printf("%d\n",ans.C);
	}
	return 0;
}