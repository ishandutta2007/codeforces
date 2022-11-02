#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int st[20][N],n,L,Log[N];
ll ans[N],f[N];
struct Tree{
	int l,r;
	ll num,flag;
}T[N*4];
inline int F(int x,int y){
	int ans=-1e9;
	if (x<1)x=1,ans=0;
	if (y>L)y=L,ans=0;
	int K=Log[y-x+1];
	return max(max(st[K][x],st[K][y-(1<<K)+1]),ans);
}
inline void down(int x){
	T[x*2].num+=T[x].flag;
	T[x*2+1].num+=T[x].flag;
	T[x*2].flag+=T[x].flag;
	T[x*2+1].flag+=T[x].flag;
	T[x].flag=0;
}
inline void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;
	if (l==r)return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
inline void insert(int x,int l,int r,int z){
	if (l>r)return;
	f[r+1]-=z;f[l]+=z;
}
inline void solve(int x){
	for (int i=1;i<=n;i++)f[i]+=f[i-1],ans[i]+=f[i];
}
signed main(){
	int T;
	scanf("%d%d",&T,&n);
	build(1,1,n);
	for (int i=1;i<=n;i++)Log[i]=log2(i);
	while (T--){
		scanf("%d",&L);
		for (int i=1;i<=L;i++)scanf("%d",&st[0][i]);
		for (int i=1;i<=Log[L];i++)
			for (int j=1;j<=L;j++)st[i][j]=max(st[i-1][j],st[i-1][min(L,j+(1<<i-1))]);
		for (int i=1;i<=L;i++)ans[i]+=F(L-(n-i),i);
		for (int i=n-L+1;i<=n;i++)
			if (i>L)ans[i]+=F(L-(n-i),i);
		insert(1,L+1,n-L,max(0,F(1,L)));
	}
	solve(1);
	for (int i=1;i<=n;i++)printf("%lld ",ans[i]);
}