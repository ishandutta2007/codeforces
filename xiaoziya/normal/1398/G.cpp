#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxk=20,maxn=1<<(maxk-1),mod=998244353,G=3,invG=(mod+1)/3,maxt=maxn<<2,base=200000;
typedef vector<int>poly;
int n,X,Y,q;
int btf[maxn],w[maxk][maxn][2],fu[2]={1,mod-1};
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
void init(){
	for(int len=2,i=1;i<maxk;len<<=1,i++){
		int o0=ksm(G,(mod-1)/len),o1=ksm(invG,(mod-1)/len);
		w[i][0][0]=w[i][0][1]=1;
		for(int j=1;j<len;j++)
			w[i][j][0]=1ll*w[i][j-1][0]*o0%mod,w[i][j][1]=1ll*w[i][j-1][1]*o1%mod;
	}
}
int getlen(int n){
	int r=0;
	while((1<<r)<n)
		r++;
	for(int i=0;i<(1<<r);i++)
		btf[i]=(btf[i>>1]>>1)|((i&1)<<(r-1));
	return (1<<r);
}
void NTT(poly &x,int lim,int opt){
	x.resize(lim);
	for(int i=0;i<lim;i++)
		if(i<btf[i])
			swap(x[i],x[btf[i]]);
	for(int p=1,l=2;l<=lim;p++,l<<=1)
		for(int i=0;i<lim;i+=l)
			for(int j=0;j<(l>>1);j++){
				int a=x[i+j],b=1ll*x[i+j+(l>>1)]*w[p][j][opt]%mod;
				x[i+j]=(a+b)%mod,x[i+j+(l>>1)]=(a-b+mod)%mod;
			}
	if(opt==1){
		int v=ksm(lim,mod-2);
		for(int i=0;i<lim;i++)
			x[i]=1ll*x[i]*v%mod;
	}
}
poly operator *(poly a,poly b){
	int deg=a.size()+b.size()-1,lim=getlen(deg);
	poly res(lim);
	NTT(a,lim,0),NTT(b,lim,0);
	for(int i=0;i<lim;i++)
		res[i]=1ll*a[i]*b[i]%mod;
	NTT(res,lim,1),res.resize(deg);
	return res;
}
int ans[maxn];
int main(){
	init();
	scanf("%d%d%d",&n,&X,&Y);
	poly a(base+1),b(base+1);
	for(int i=0,x;i<=n;i++)
		scanf("%d",&x),a[x]=1,b[base-x]=1;
	poly f=a*b;
	for(int i=base+1;i<f.size();i++)
		if(f[i]){
			int k=2*(i-base+Y);
			for(int j=k;j<=1e6;j+=k)
				ans[j]=k;
		}
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%d ",ans[x]==0? -1:ans[x]);
	}
	puts("");
	return 0;
}