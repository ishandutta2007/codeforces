//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
const int N = 1100000;

struct poly{
	ull P2 = (ull)mod*mod;
	int wroot = 3;
	int n,l,rev[N],mrt[N],rcrt[N*4] = {0},invn,MXNTT = 1<<20;
	void polysub(int a[],int b[],int c[],int sz){
		for(int i=0;i<sz;i++) c[i] = sub(a[i],b[i]);
	}
	void polyadd(int a[],int b[],int c[],int sz){
		for(int i=0;i<sz;i++) c[i] = add(a[i],b[i]);
	}
	void polycoef(int a[],int sz,int coef){
		for(int i=0;i<sz;i++) a[i] = mul(a[i],coef);
	}
	void polyclear(int a[],int sz){
		memset(a,0,sizeof(int)*sz+4);
	}
	void polydot(int a[],int b[],int c[],int sz){
		for(int i=0;i<sz;i++)c[i] = mul(a[i],b[i]);
	}
	int uptopow(int x){
		while(x!=(x&(-x)))x+=x&(-x);
		return x;
	}
	int uptopow(int a[],int n){
		int nn=uptopow(n);
		for(int i=n;i<nn;i++)a[i]=0;
		return nn;
	}
	void NTT_ori(){
		int stepv = pow(wroot,(mod-1)/MXNTT);
		mrt[0] = 1;
		for(int i=1;i<=MXNTT;i++)mrt[i] = mul(mrt[i-1],stepv);
		for(int l=2;l<=MXNTT;l<<=1){
			int m = l/2;
			int step = MXNTT/l;
			for(int i=0,j = MXNTT;i<m;i++,j-=step)rcrt[i+m+N] = mrt[j];
			for(int i=0,j = 0;i<m;i++,j+=step){
				//cout<<i+m<<' '<<j<<endl;
				rcrt[i+m] = mrt[j];
			}
		}
		//cout<<rcrt[3]<<endl;
	}
	void NTT_init(int sz){
		if(n == uptopow(sz))return;
		sz = n = uptopow(sz);
		l = 0;
		while(1<<l < sz)l++;
		rev[0] = 0;
		for(int i=0;i<n;i++)rev[i] = i&1?(rev[i>>1]>>1)|(1<<(l-1)):(rev[i>>1]>>1);
	}
	void DFT(int ipt[],int typ){
		
		//typ == 0 : DFT
		//typ == 1 : IDFT
		static ull a[N];
		for(int i=0;i<n;i++)a[rev[i]] = ipt[i];
		for(int l=2;l<=n;l<<=1){
			int m = l/2;
			int step = MXNTT/l;
			int *crt = typ?rcrt+m+N:rcrt+m;
			
			if(l==(1<<17)){
				for(int b = 0;b!=n;b+=l)
					for(int i=0;i<m;i++){
						ull x = a[b+i]%mod,y = a[b+i+m]%mod*crt[i];
						a[b+i+m] = x+P2-y;
						a[b+i] = x+y;
					}
			}
			else{
				for(int b = 0;b!=n;b+=l)
					for(int i=0;i<m;i++){
						ull x = a[b+i],y = a[b+i+m]%mod*crt[i];
						a[b+i+m] = x+P2-y;
						a[b+i] = x+y;
					}
			}
		}
		
		if(typ){
			invn = pow(n,mod-2);
			for(int i=0;i<n;i++)a[i] = a[i]%mod*invn;
		}
		for(int i=0;i<n;i++)ipt[i] = a[i]%mod;
	}
	void polymul(int a[],int asz,int b[],int bsz,int c[],int csz=-1){
		static int cc1[N],cc2[N];
		if(csz == -1)csz = asz+bsz;
		int sz = uptopow(asz+bsz);
		NTT_init(asz+bsz);
		for(int i=0;i<sz;i++)cc1[i] = i<asz?a[i]:0,cc2[i] = i<bsz?b[i]:0;
		//cout<<"A :"; for(int i=0;i<asz;i++) cout<<a[i]<<' '; cout<<endl;
		//cout<<"B :"; for(int i=0;i<asz;i++) cout<<b[i]<<' '; cout<<endl;
		DFT(cc1,0);
		DFT(cc2,0);
		polydot(cc1,cc2,cc1,sz);
		DFT(cc1,1);
		for(int i=0;i<csz;i++)c[i] = cc1[i];
	}
}NTT;
int n,m,a[N],b[N],c[N],tmp[N];
int main(){
	read(n);
	NTT.NTT_ori();
	int ans = 0;
	a[0] = 1;a[1] = 0;a[2] = 0;
	b[0] = 0;b[1] = 1;b[2] = 0;
	for(int i=2;i*2-1<=n;i*=2){
		for(int j=0;j<=i;j++){
			tmp[j] = b[j];
			if(j%2 == 0) tmp[j]=0;
		}
		NTT.polymul(tmp,i+1,b,i+1,c);
		for(int j=0;j<=i;j++){
			tmp[j] = a[j];
			if(j%2 != 0) tmp[j]=0;
		}
		NTT.polymul(tmp,i+1,b,i+1,b);
		for(int j=0;j<=i*2;j++)a[j] = c[j];
		//for(int j=0;j<=i*2;j++) cout<<a[j]<<' '; cout<<endl;
		//for(int j=0;j<=i*2;j++) cout<<b[j]<<' '; cout<<endl;
	}
	int i = 10;
	int ai = 1;
	while(ai*2+1<=n){
		ai = ai*2+1;
	}
	//cout<<n-ai<<' '<<b[n-ai]<<' '<<a[n-ai]<<endl;
	cout<<add(b[n-ai],a[n-ai])<<endl;
	return 0;
}