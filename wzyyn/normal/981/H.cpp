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
const int mo=998244353;
const int FFTN=(1<<17);
const int N=FFTN+5;
int fac[N],inv[N];
int A[N],B[N],R[N];
int w[N],W[N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	W[0]=1; W[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) W[i]=1ll*W[i-1]*W[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	For(i,0,n-1) a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int val=1ll*inv[n]*fac[n-1]%mo;
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
vector<int> mult(vector<int> a,vector<int> b){
	vector<int> ans;
	int sza=a.size()-1,szb=b.size()-1;
	ans.resize(sza+szb+1);
	if (sza+szb<=1){
		For(i,0,sza) For(j,0,szb)
			ans[i+j]=(ans[i+j]+1ll*a[i]*b[j])%mo;
	}
	else{
		int L=FFTinit(sza+szb);
		For(i,0,L-1) A[i]=(i<=sza?a[i]:0);
		For(i,0,L-1) B[i]=(i<=szb?b[i]:0);
		DFT(A,L); DFT(B,L);
		For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
		IDFT(A,L);
		For(i,0,sza+szb) ans[i]=A[i];
	}
	return ans;
}
vector<int> divide(int l,int r,vector<int> &tmp){
	if (l==r){
		vector<int> ans;
		ans.PB(1);
		ans.PB(tmp[l]);
		return ans;
	}
	int mid=(l+r)/2;
	return mult(divide(l,mid,tmp),divide(mid+1,r,tmp));
}
vector<int> solve(vector<int> tmp){
	int sz=tmp.size();
	if (!sz){
		vector<int> ans;
		ans.PB(1);
		return ans;
	}
	return divide(0,sz-1,tmp);
}
int sz[N],fa[N];
vector<int> f[N];
int vf[N],vg[N],sf[N];
int n,k,ans,ff[N];
vector<int> e[N]; 
map<int,int> mp;
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			sz[x]+=sz[i];
			sf[x]=(sf[x]+sf[i])%mo;
		}
	vector<int> tmp;
	for (auto i:e[x])
		if (i!=fa[x])
			tmp.PB(sz[i]);
	f[x]=solve(tmp);
	For(i,0,min((int)f[x].size()-1,k-1))
		vf[x]=(vf[x]+1ll*fac[k]*inv[k-i]%mo*f[x][i])%mo;
	sf[x]=(sf[x]+vf[x])%mo;
	//cout<<x<<' '<<vf[x]<<endl;
}
void dfs2(int x){
	ans=(ans+1ll*vf[x]*vg[x])%mo;
	//cout<<vf[x]<<' '<<vg[x]<<endl;
	mp.clear();
	if (x!=1){
		f[x].PB(0);
		int m=f[x].size();
		Rep(i,m-2,0) f[x][i+1]=(f[x][i+1]+1ll*f[x][i]*(n-sz[x]))%mo;
	}
	mp.clear();
	for (auto i:e[x])
		if (i!=fa[x]){
			if (!mp[sz[i]]){
				int m=f[x].size();
				For(j,0,m-1) ff[j]=f[x][j];
				For(j,0,m-2) ff[j+1]=(ff[j+1]+mo-1ll*ff[j]*sz[i])%mo;
				int vson=vg[x];
				For(j,0,min(m-2,k-1))
					vson=(vson+2ll*fac[k]*inv[k-j]%mo*ff[j])%mo;
				mp[sz[i]]=vson;
			}
			vg[i]=mp[sz[i]];
			vg[i]=(vg[i]+sf[x]+2ll*mo-sf[i]-vf[x])%mo;
		}
	for (auto i:e[x])
		if (i!=fa[x])
			dfs2(i);
}
int main(){
	init();
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x); 
	}
	dfs(1);
	dfs2(1);
	ans=1ll*(mo+1)/2*ans%mo;
	printf("%d\n",ans);
	
} 
/*
FFT
map 
*/