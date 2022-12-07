#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=155;
struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		return v<a.v;
	}
}e[N];
int n,m,ans;
int q[N],dis[N],E[N][N];
struct Mat{
	uint a[N][5];
	Mat(){
		memset(a,0,sizeof(a));
	}
	void set(int x,int y){
		a[x][y>>5]|=1u<<(y&31);
	}
	int get(int x,int y)const{
		return (a[x][y>>5]>>(y&31))&1;
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,1,n) For(j,1,n) if (get(i,j))
			For(k,0,4) ans.a[i][k]|=b.a[j][k];
		return ans;
	}
}s,tr,tmp;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+m+1);
	e[m+1]=(edge){-1,-1,1<<30};
	if (e[1].v) return puts("Impossible"),0;
	For(i,1,n) s.set(i,i);
	int clk=0,ans=1<<30;
	For(i,1,m){
		E[e[i].x][e[i].y]=1;
		tr.set(e[i].x,e[i].y); tmp=tr;
		int T=e[i+1].v-e[i].v,t=0;
		For(j,1,n) dis[j]=-1;
		For(j,1,n) if (s.get(1,j))
			q[++t]=j,dis[j]=e[i].v;
		For(j,1,t) For(k,1,n)
			if (E[q[j]][k]&&dis[k]==-1)
				q[++t]=k,dis[k]=dis[q[j]]+1;
		if (dis[n]!=-1) ans=min(ans,dis[n]);
		for (;T;T/=2,tmp=tmp*tmp)
			if (T&1) s=s*tmp;
		//printf("%d %d %d\n",s.get(1,1),s.get(1,2),s.get(1,3));
	}
	if (ans==(1<<30))
		puts("Impossible");
	else printf("%d\n",ans);
}