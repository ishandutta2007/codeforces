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
const int FFTN=1<<19;
const int N=FFTN+5;
int w[N],W[N],R[N];
int A[N],B[N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
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
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
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
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
int key[30],tr[30],n,m;
char s[N],t[N];
int s1[N],flg[N];
void check(){
	For(i,1,26) key[i]=rand()*32768+rand();
	int L=FFTinit(n+m),s2=0;
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,1,m) s1[i]=(s1[i-1]+1ll*key[s[i]]*key[s[i]])%mo;
	For(i,1,n) s2=(s2+1ll*key[t[i]]*key[tr[t[i]]])%mo;
	
	For(i,1,n) A[n-i]=(key[t[i]]+key[tr[t[i]]])%mo;
	For(i,1,m) B[i]=key[s[i]]%mo;
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	
	For(i,1,m-n+1){
		int val=(s1[i+n-1]+mo-s1[i-1])%mo;
		//cout<<val<<' '<<s2<<' '<<A[i+n-1]<<endl;
		val=(val+s2+1ll*mo-A[i+n-1])%mo;
		if (val) flg[i]=0;
	}
	//cout<<endl;
}
int main(){
	FFTinit();
	srand(time(NULL));
	For(i,1,26) scanf("%d",&tr[i]);
	scanf("%s",t+1);
	scanf("%s",s+1);
	n=strlen(t+1);
	m=strlen(s+1);
	For(i,1,n) t[i]=t[i]-'a'+1;
	For(i,1,m) s[i]=s[i]-'a'+1;
	For(i,1,m-n+1) flg[i]=1;
	For(T,1,2) check();
	For(i,1,m-n+1) putchar(flg[i]+'0');
}
/*
2*(1+2)
3*(2+3)
1*(3+1) 
(x-a)*(x-b)
x^2-x(a+b)+ab
*/