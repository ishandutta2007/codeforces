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
const int mo=998244353;
int n,m,top,s[N],l[N],r[N],a[25],b[25];
int vis[N],q[45],sway[45][N];
int SC[45][45],ans,ran[85];
int fac[N],inv[N];
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
int main(){
	init();
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d%d",&l[i],&r[i]);
	For(i,1,m){
		scanf("%d%d",&a[i],&b[i]);
		vis[a[i]]=vis[b[i]]=1;
	}
	For(i,1,n) if (vis[i]) q[++*q]=i;
	ran[++top]=1;
	ran[++top]=n+1;
	For(i,1,n) if (vis[i]){
		ran[++top]=l[i];
		ran[++top]=r[i]+1;
	}
	sort(ran+1,ran+top+1);
	top=unique(ran+1,ran+top+1)-ran-1;
	For(i,1,n) if (!vis[i]) ++s[l[i]],--s[r[i]+1];
	For(i,1,n+1) s[i]+=s[i-1];//cout<<s[i]<<' ',cout<<endl;
	For(i,0,2*m) For(j,1,n)
		sway[i][j]=(sway[i][j-1]+C(s[j],j-i))%mo;
	For(i,0,40) SC[i][0]=1;
	For(i,1,40) For(j,1,i)
		SC[i][j]=(SC[i-1][j]+SC[i-1][j-1])%mo;
	For(p,1,top-1){
		int st=0;
		For(i,1,m){
			bool flg=1;
			if (ran[p]<l[a[i]]||ran[p]>r[a[i]]) flg=0;
			if (ran[p]<l[b[i]]||ran[p]>r[b[i]]) flg=0;
			if (flg) st|=1<<(i-1);
		}
		For(i,0,(1<<m)-1) if ((st&i)==i){
			int flg=0;
			For(j,1,*q) vis[q[j]]=0;
			For(j,1,m) if (i&(1<<(j-1)))
				flg^=1,vis[a[j]]=vis[b[j]]=1;
			int sum1=0,sum2=0,way=0;
			For(j,1,*q) if (vis[q[j]]) ++sum1;
			For(j,1,*q) if (!vis[q[j]])
				if (l[q[j]]<=ran[p]&&ran[p]<=r[q[j]]) ++sum2;
			For(j,0,sum2) way=(way+1ll*SC[sum2][j]*(sway[j+sum1][ran[p+1]-1]+mo-sway[j+sum1][ran[p]-1]))%mo;
			ans=(ans+(flg?mo-way:way))%mo;
			//cout<<p<<' '<<i<<' '<<flg<<' '<<way<<' '<<sum1<<' '<<sum2<<endl;
		}
	}
	cout<<ans<<endl;
}
/*
3 0
1 1
2 3
1 3

*/