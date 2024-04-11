#include<cstdio>
#include<algorithm>
const int N=400005;
const int P=998244353;
int n,m,lim,a[N],b[N],c[N],r[N],f[N],g[N];
int fpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;
	return res;
}
void ntt(int*a,int g){
	for(int i=0;i<lim;++i)if(i<r[i])std::swap(a[i],a[r[i]]);
	for(int i=1;i<lim;i<<=1){
		int wn=fpow(g,(P-1)/(i<<1));
		for(int j=0;j<lim;j+=i<<1){
			int w=1;
			for(int k=0;k<i;++k,w=1ll*w*wn%P){
				int x=a[j+k],y=1ll*w*a[i+j+k]%P;
				a[j+k]=(x+y)%P,a[i+j+k]=(x-y+P)%P;
			}
		}
	}
	if(g==332748118){
		int tmp=fpow(lim,P-2);
		for(int i=0;i<lim;++i)a[i]=1ll*a[i]*tmp%P;
	}
}
void pinv(int*a,int*b,int big){
	if(big==1)return b[0]=fpow(a[0],P-2),void();
	pinv(a,b,big>>1);int len=0;lim=1;
	while(lim<=big)lim<<=1,++len;
	for(int i=0;i<lim;++i)r[i]=(r[i>>1]>>1)|((i&1)<<len-1);
	for(int i=0;i<big;++i)f[i]=a[i],g[i]=b[i];for(int i=big;i<lim;++i)f[i]=g[i]=0;
	ntt(f,3),ntt(g,3);
	for(int i=0;i<lim;++i)f[i]=1ll*f[i]*g[i]%P*g[i]%P;
	ntt(f,332748118);
	for(int i=0;i<big;++i)b[i]=((b[i]+b[i]-f[i])%P+P)%P;
}
int inv2=fpow(2,P-2); 
void psqrt(int*a,int*b,int big){
	if(big==1){b[0]=1;return;}
	psqrt(a,b,big>>1);
	int len=0;lim=1;while(lim<=big)lim<<=1,++len;
	for(int i=0;i<lim;++i)r[i]=(r[i>>1]>>1)|((i&1)<<len-1),c[i]=0; 
	pinv(b,c,big);
	for(int i=0;i<big;++i)f[i]=b[i];for(int i=big;i<lim;++i)f[i]=0;
	ntt(f,3);
	for(int i=0;i<lim;++i)f[i]=1ll*f[i]*f[i]%P;
	ntt(f,332748118);
	for(int i=0;i<big;++i)b[i]=(f[i]+a[i])%P;
	for(int i=0;i<big;++i)b[i]=1ll*b[i]*inv2%P;
	ntt(b,3),ntt(c,3);
	for(int i=0;i<lim;++i)b[i]=1ll*b[i]*c[i]%P;
	ntt(b,332748118);
	for(int i=big;i<lim;++i)b[i]=c[i]=0;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0,x;i<m;++i){
		scanf("%d",&x);a[x]=1;
	}
	int big=1;while(big<=n)big<<=1;
	for(int i=0;i<big;++i)a[i]=(P-4*a[i])%P;
	++a[0]%=P;
	psqrt(a,b,big);
	++b[0]%=P;
	for(int i=0;i<big;++i)a[i]=f[i]=g[i]=0;
	pinv(b,a,big);
	for(int i=1;i<=n;++i)printf("%d\n",(a[i]+a[i])%P);
	return 0;
}