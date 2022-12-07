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
const int N=200005;
int n,m,K,vis[N];
int L[N],R[N],q[N];
int ban[N],bam[N];
int cnt[1<<8],f[1<<8],g[1<<8];
pii qq[N];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	For(i,1,n) scanf("%d%d",&L[i],&R[i]);
	For(i,1,n) q[++*q]=L[i],q[++*q]=R[i]+1;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,n){
		int vL=lower_bound(q+1,q+*q+1,L[i])-q;
		int vR=lower_bound(q+1,q+*q+1,R[i]+1)-q-1;
		//cout<<vL<<' '<<vR<<endl;
		qq[i]=pii(vL,vR);
		vis[i]=-1;
	}
	sort(qq+1,qq+n+1);
	For(i,0,(1<<K)-1) cnt[i]=cnt[i/2]^(i&1);
	For(i,0,K-1){
		int px=0;
		For(j,1,n)
			if (vis[j]==-1&&qq[j].fi>px){
				vis[j]=i;
				//cout<<i<<' '<<j<<endl;
				px=qq[j].se;
				ban[qq[j].se+1]|=1<<i;
				bam[qq[j].fi]|=1<<i;
			}
	}
	memset(f,155,sizeof(f));
	f[0]=0;
	For(i,1,(*q)-1){
		//cout<<i<<' '<<ban[i]<<' '<<bam[i]<<endl;
		memset(g,155,sizeof(g));
		For(j,0,(1<<K)-1) g[j^(j&ban[i])]=max(g[j^(j&ban[i])],f[j]);
		memset(f,155,sizeof(f));
		For(j,0,(1<<K)-1) f[j]=max(f[j],g[j^(j&bam[i])]);
		For(j,0,(1<<K)-1) if (cnt[j]) f[j]+=q[i+1]-q[i];
		//For(j,0,(1<<K)-1) cout<<f[j]<<' '<<g[j]<<' '; cout<<endl;
	}
	int ans=0;
	For(j,0,(1<<K)-1) ans=max(ans,f[j]);
	printf("%d\n",ans);
}
/*
2 10 2
1 3
2 6 
*/