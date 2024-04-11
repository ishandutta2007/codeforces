#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int M=262144;
//head
const int mo=998244353,g=3;

int qp(int a,int b){int an=1;for(;b;b>>=1){if(b&1)an=1ll*an*a%mo;a=1ll*a*a%mo;}return an;}
void dft(int *a,int n,int fl=1){
	for (int i=n>>1,j=1,k;j<n-1;j++){
		if(i>j)swap(a[i],a[j]);
		for (k=n>>1;k<=i;k>>=1)i^=k;i^=k;
	}
	for (int m=2;m<=n;m<<=1)
		for (int i=0,wm=qp(g,fl==1?(mo-1)/m:(mo-1)/m*(m-1));i<n;i+=m)
			for (int j=i,w=1;j<i+(m>>1);j++){
				int u=a[j],v=1ll*w*a[j+(m>>1)]%mo;
				if((a[j]=u+v)>=mo)a[j]-=mo;
				if((a[j+(m>>1)]=u-v)<0)a[j+(m>>1)]+=mo;
				w=1ll*w*wm%mo;
			}
	if(fl==-1){
		int tm=qp(n,mo-2);
		for (int i=0;i<n;i++)a[i]=1ll*a[i]*tm%mo;
	}
}
int tmp[M];
void inv(int *a,int n,int *b){
	b[0]=qp(a[0],mo-2);b[1]=0;
	for(int m=2;m<=n;m<<=1){
		re(i,0,m)tmp[i]=a[i];re(i,m,2*m)tmp[i]=b[i]=0;
		dft(tmp,2*m);dft(b,2*m);
		re(i,0,2*m)b[i]=1ll*b[i]*(2-1ll*tmp[i]*b[i]%mo+mo)%mo;
		dft(b,2*m,-1);
		re(i,m,2*m)b[i]=0;
	}
}
int tmp1[M],rb[M];
void squarert(int *a,int n,int *b){
	b[0]=1;b[1]=0;
	int r2=qp(2,mo-2);
	for(int m=2;m<=n;m<<=1){
		re(i,0,m)tmp1[i]=a[i];re(i,m,2*m)tmp1[i]=b[i]=0;
		dft(tmp1,2*m);
		inv(b,m,rb);
		dft(rb,2*m);
		dft(b,2*m);
		re(i,0,2*m)b[i]=(1ll*r2*b[i]+1ll*r2*tmp1[i]%mo*rb[i])%mo;
		dft(b,2*m,-1);
		re(i,m,2*m)b[i]=0;
	}
}
int a[M],b[M],c[M];
int n,m;
int main() {
	read(n,m);int N=1;while(N<=m)N<<=1;
	rep(i,1,n){
		int x;read(x);
		a[x]=mo-4;
	}
	a[0]=1;
	squarert(a,N,b);b[0]+=1;
	inv(b,N,c);
	rep(i,1,m)printf("%d\n",c[i]*2ll%mo);
	return 0;
}