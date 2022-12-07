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
const int N=2005;
int n,m,Q,Ans[N],ans;
int x[N],y[N];
int L[N][N],R[N][N];
char s[N][N];
void build(int id){
	L[id][0]=R[id][m+1]=0;
	For(i,1,m) L[id][i]=(s[id][i]=='X'?0:L[id][i-1]+1);
	Rep(i,m,1) R[id][i]=(s[id][i]=='X'?0:R[id][i+1]+1);
}
bool check(int y,int L,int R,int v){
	static int va[N],vb[N],q[N],sum[N];
	For(i,L,R) sum[i]=0;
	For(i,L,R) va[i]=::L[i][y];
	For(i,L,R) vb[i]=::R[i][y];
	int h=1,t=0;
	For(i,L,R){
		if (h<=t&&q[h]<=i-v) ++h;
		for (;h<=t&&va[i]<=va[q[t]];--t);
		q[++t]=i; sum[i]+=va[q[h]];
	}
	h=1,t=0;
	For(i,L,R){
		if (h<=t&&q[h]<=i-v) ++h;
		for (;h<=t&&vb[i]<=vb[q[t]];--t);
		q[++t]=i; sum[i]+=vb[q[h]];
	}
	For(i,L+v-1,R)
		if (sum[i]>=v+1)
			return 1;
	return 0;
}
int main(){
	ans=1;
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,Q) scanf("%d%d",&x[i],&y[i]);
	For(i,1,Q) s[x[i]][y[i]]='X';
	For(i,1,n) build(i);
	For(i,1,m) for (;check(i,1,n,ans);++ans);
	Rep(i,Q,1){
		Ans[i]=ans;
		s[x[i]][y[i]]='.'; build(x[i]);
		for (;check(y[i],max(1,x[i]-ans),min(n,x[i]+ans),ans);++ans);
	}
	For(i,1,Q)
		printf("%d\n",Ans[i]-1);
}