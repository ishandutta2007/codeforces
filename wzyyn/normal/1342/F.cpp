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
int cnt[1<<15];
int g[1<<15][15];
int f[1<<15][15][16];
pii fr[1<<15][15][16];
int s[1<<15],n;
void init(){
	For(i,0,(1<<15)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<15)-1) For(j,0,14) g[i][j]=-1;
	For(i,0,(1<<15)-1) For(j,0,14) Rep(k,14,j)
		if (i&(1<<k)) g[i][j]=k;
}
bool Mn(int &x,int y){
	return x>y?x=y,1:0;
}
void solve(){
	scanf("%d",&n);
	For(i,0,n-1) scanf("%d",&s[1<<i]);
	For(i,1,(1<<n)-1) s[i]=s[i&(-i)]+s[i-(i&(-i))];
	For(i,0,(1<<n)-1) For(j,0,n-1) For(k,0,n) f[i][j][k]=1<<30;
	For(i,0,(1<<n)-1) f[i][g[i][0]][1]=s[i];
	For(i,0,(1<<n)-1) fr[i][g[i][0]][1]=pii(i,-1);
	For(i,1,(1<<n)-1) For(j,0,n-1) if (i&(1<<j))
		for (int op=(1<<n)-1-i,k=op;k;k=(k-1)&op){
			int nk=g[k][j];
			For(l,1,cnt[i]) if (s[k]>f[i][j][l])
				if (Mn(f[i|k][nk][l+1],s[k]))
					fr[i|k][nk][l+1]=pii(k,j);
		}
	static pii op[20];
	static int rk[20],top;
	static int sta[20],pos[20]; 
	int p1=0,p2=0; top=0;
	For(k,1,n) For(j,0,n-1) 
		if (f[(1<<n)-1][j][k]!=1<<30)
			p1=j,p2=k;
	for (int tmp=p2,S=(1<<n)-1;tmp;--tmp){
		int v1=fr[S][p1][tmp].fi;
		int v2=fr[S][p1][tmp].se;
		sta[tmp]=v1; pos[tmp]=p1;
		//cout<<tmp<<' '<<v1<<' '<<p1<<' '<<p2<<' '<<S<<endl;
		p1=v2; S-=v1;
	}
	For(i,0,n-1) rk[i]=i+1;
	For(i,1,p2) For(j,0,n-1)
		if (j!=pos[i]&&((1<<j)&sta[i])){
			op[++top]=pii(rk[j],rk[pos[i]]);
			For(k,j,n-1) --rk[k];
		}
	printf("%d\n",top);
	For(i,1,top) printf("%d %d\n",op[i].fi,op[i].se);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}