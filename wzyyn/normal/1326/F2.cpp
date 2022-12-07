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
const int N=20,M=1<<18|5;
struct state{
	int a[20];
	bool operator <(const state &b)const{
		For(i,0,19)
			if (a[i]!=b.a[i])
				return a[i]<b.a[i];
		return 0;
	}
}sta[1005];
map<state,int> mp;
int top,n,p,cnt[M];
char tr[N][N];
ll f[M][N],g[N][M];
ll val[1005],h[M];
void dfs(int n,int d,state tmp){
	if (!n){
		sta[++top]=tmp;
		mp[tmp]=top;
		return;
	}
	if (n<d) return;
	for (;n>=0;n-=d){
		dfs(n,d+1,tmp);
		tmp.a[d]++;
	}
}
void dfss(int n,int d,ll v1,int S){
	if (!n) return val[++p]+=v1,void(0);
	if (n<d) return;
	for (;n>=0;n-=d){
		dfss(n,d+1,v1,S);
		v1*=g[d][S];
	}
}
int main(){
	scanf("%d",&n);
	For(i,0,n-1) scanf("%s",tr[i]);
	For(i,0,n-1) For(j,0,n-1) tr[i][j]-='0';
	For(i,0,(1<<n)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,n-1) f[1<<i][i]=1;
	For(i,0,(1<<n)-1) For(j,0,n-1) if (i&(1<<j))
		For(k,0,n-1) if (!(i&(1<<k)))
			if (!tr[j][k]) f[i|(1<<k)][k]+=f[i][j];
	For(i,0,(1<<n)-1) For(j,0,n-1) g[cnt[i]][i]+=f[i][j];
	For(s,0,n)
		for (int d=1;d<1<<n;d<<=1)
			for (int i=0;i<1<<n;i+=d<<1)
				for (int j=0;j<d;j++)
					g[s][i+j+d]+=g[s][i+j];
	state tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	//cerr<<top<<endl;
	dfs(n,1,tmp);
	For(i,0,(1<<n)-1)
		p=0,dfss(n,1,((n-cnt[i])&1?-1:1),i);
	--n;
	For(i,0,(1<<n)-1){
		memset(tmp.a,0,sizeof(tmp.a));
		int l=0;
		For(j,0,n)
			if ((i&(1<<j))||j==n)
				++tmp.a[l+1],l=0;
			else ++l;
		h[i]=val[mp[tmp]];
	}
	for (int d=1;d<1<<n;d<<=1)
		for (int i=0;i<1<<n;i+=(d<<1))
			for (int j=0;j<d;j++)
				h[i+j+d]-=h[i+j];
	For(i,0,(1<<n)-1)
		printf("%lld ",h[i]);
}