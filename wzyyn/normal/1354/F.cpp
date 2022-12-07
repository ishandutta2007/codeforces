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
const int N=80;
int n,k,a[N],b[N];
int q[N],id[N];
int pre[N][N];
ll f[N][N];
bool cmp(int x,int y){
	return b[x]<b[y];
}
void construct(){
	int p1=n,p2=n-1,j=k;
	Rep(i,n,1){
		if (pre[i][j]==j) q[p2--]=id[i];
		else if (p1==n) q[p1]=id[i],p1=k-1;
		else q[p1--]=id[i];
		j=pre[i][j];
	}
	printf("%d\n",n*2-k);
	For(i,1,k-1) printf("%d ",q[i]);
	For(i,k,n-1) printf("%d %d ",q[i],-q[i]);
	printf("%d\n",q[n]);
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&a[i],&b[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	For(i,0,n-1) For(j,0,k){
		ll w=f[i][j]+b[id[i+1]]*(k-1);
		if (w>f[i+1][j]) f[i+1][j]=w,pre[i+1][j]=j;
		if (j==k) continue;
		w=f[i][j]+a[id[i+1]]+b[id[i+1]]*(j);
		if (w>f[i+1][j+1]) f[i+1][j+1]=w,pre[i+1][j+1]=j;
	}
	//while(1);
	construct();
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
3
5 2
5 3
7 0
5 0
4 0
10 0
2 1
10 100
50 10
5 5
1 5
2 4
3 3
4 2
5 1

*/