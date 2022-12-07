#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=300005;
vector<int> e[N];
int d[N],q[N],n;
int f[N][20];
ll sum;
void dfs(int x,int fa){
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			d[x]=max(d[x],d[i]);
		}
	d[x]++;
	sum+=d[x];
	f[x][1]=n;
	For(j,2,18){
		*q=0;
		for (auto i:e[x])
			if (i!=fa) q[++*q]=f[i][j-1];
		sort(q+1,q+*q+1);
		reverse(q+1,q+*q+1);
		int p=0;
		for (;p!=*q&&q[p+1]>=p+1;++p);
		f[x][j]=p;
	}
}
void solve(int x,int fa){
	for (auto i:e[x])
		if (i!=fa){
			solve(i,x);
			For(j,1,18) f[x][j]=max(f[x][j],f[i][j]);
		}
	For(j,1,18)
		if (f[x][j]>=1)
			sum+=f[x][j]-1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	//cout<<sum<<endl;
	solve(1,0);
	printf("%lld\n",sum);
}