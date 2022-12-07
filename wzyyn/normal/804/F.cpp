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
const int N=5005;
const int M=2000005;
const int mo=1000000007;
bool e[N][N];
int dfn[N],low[N],vis[N];
int n,A,B,tot,fac[N],inv[N];
int l[N],G[N],be[N],stk[N];
int lo[N],hi[N],ans;
vector<int> v[N],ok[N];
char s[M];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
} 
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	vis[x]=1; stk[++*stk]=x;
	For(i,1,n)
		if (i!=x&&e[x][i]){
			if (!dfn[i]){
				tarjan(i);
				low[x]=min(low[x],low[i]);
			}
			else if (vis[i])
				low[x]=min(low[x],dfn[i]);
		}
	if (low[x]==dfn[x]){
		++tot;
		int y=19260817;
		for (;y!=x;){
			y=stk[(*stk)--];
			vis[y]=0; be[y]=tot;
		}
	}
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,n) e[i][j]+=(s[j]=='1');
	}
	For(i,1,n){
		scanf("%d%s",&l[i],s+1);
		For(j,1,l[i]) v[i].PB(s[j]=='1');
	}
	For(i,1,n)
		if (!dfn[i])
			tarjan(i);
	For(i,1,n) G[be[i]]=gcd(G[be[i]],l[i]);
	//For(i,1,n) cout<<be[i]<<endl;
	For(i,1,tot) ok[i].resize(G[i]);
	For(i,1,n) For(j,0,l[i]-1)
		ok[be[i]][j%G[be[i]]]|=v[i][j];
	//Rep(i,tot,1) cout<<G[i]<<endl;
	Rep(i,tot,2){
		static int OK[M];
		int l=gcd(G[i],G[i-1]);
		For(j,0,l-1) OK[j]=0;
		For(j,0,G[i]-1) OK[j%l]|=ok[i][j];
		For(j,0,G[i-1]-1) ok[i-1][j]|=OK[j%l]; 
	}
	For(i,1,n){
		For(j,0,l[i]-1) lo[i]+=v[i][j];
		For(j,0,l[i]-1) hi[i]+=ok[be[i]][j%G[be[i]]];
		//cout<<lo[i]<<' '<<hi[i]<<endl; 
	}
	init();
	For(i,1,n) For(j,i+1,n)
		if (hi[i]<hi[j]){
			swap(lo[i],lo[j]);
			swap(hi[i],hi[j]);
		} 
	For(i,1,n){
		int s1=0;
		For(j,1,i-1) if (lo[j]>hi[i]) ++s1;
		For(j,0,s1) if (B>j&&s1-j<=A-B)
			ans=(ans+1ll*C(s1,j)*C(i-s1-1,B-j-1))%mo;
	}
	printf("%d\n",ans);
}
/*
hi
lo
*/