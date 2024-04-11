#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
int n,k,a[20];
int x[20],y[20],z[20];
bool f[65536][2005];
priority_queue<pii> Q;
pii tmp[20];
void output(int d){
	int T=0;
	Rep(i,d,0){
		int S=x[i]+y[i];
		for (;S!=z[i];S/=k,++T);
		Q.push(pii(T,y[i])); 
	}
	puts("YES");
	For(i,1,d){
		pii x=Q.top(); Q.pop();
		pii y=Q.top(); Q.pop();
		assert(x.fi==y.fi);
		printf("%d %d\n",x.se,y.se);
		x.se+=y.se;
		for (;x.se%k==0;x.se/=k,--x.fi);
		Q.push(x);
	}
	exit(0);
}
void dfs(int sta,int S,int d){
	if (sta==(1<<n)-1){
		if (S==1) output(d-1);
		return;
	}
	if (f[sta][S]) return;
	For(i,0,n-1)
		if (!(sta&(1<<i))){
			int nS=0;
			x[d]=S; y[d]=a[i]; z[d]=S+a[i];
			for (;;){
				dfs(sta|(1<<i),z[d],d+1);
				if (z[d]%k) break;
				z[d]/=k;
			}
		}
	f[sta][S]=1;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,0,n-1) scanf("%d",&a[i]);
	dfs(0,0,0);
	puts("NO");
}