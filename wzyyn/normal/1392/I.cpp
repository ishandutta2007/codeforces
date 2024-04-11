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
const int FFTN=1<<18;
const int N=FFTN+5;
int w[N],W[N],R[N];
int n,m,Q,a[N],b[N];
int A[N],B[N],C[N],D[N],E[N],F[N];
ll p1[N],e1[N],f1[N],p2[N],e2[N],f2[N];

#define db long double
namespace MTT{
	struct COMPLEX{
		db r,i;
		COMPLEX(){}
		COMPLEX(db _r,db _i){r=_r,i=_i;}
		COMPLEX operator +(const COMPLEX &a)const{
			return COMPLEX(r+a.r,i+a.i);
		}
		COMPLEX operator -(const COMPLEX &a)const{
			return COMPLEX(r-a.r,i-a.i);
		}
		COMPLEX operator *(const COMPLEX &a)const{
			return COMPLEX(r*a.r-i*a.i,r*a.i+i*a.r);
		}
		COMPLEX conj()const{
			return COMPLEX(r,-i);
		}
	};
	COMPLEX w[N],a[N],b[N];
	int R[N],LEN;
	const db pi=acos(-1);
	void FFTpre(){
		For(i,0,FFTN-1) w[i]=COMPLEX(cos(2*pi*i/FFTN),sin(2*pi*i/FFTN));
	}
	void FFTinit(int sz){
		for (LEN=1;LEN<=sz;LEN<<=1);
		For(i,0,LEN-1) R[i]=(R[i>>1]>>1)|((i&1)?LEN/2:0);
	}
	void DFT(COMPLEX *a,int n){
		For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
		for (int d=1,len=FFTN/2;d<n;d<<=1,len>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=i,p=0;j<i+d;j++,p+=len)
					a[j+d]=a[j]-a[j+d]*w[p],a[j]=a[j]+a[j]-a[j+d];
	}
	void Mult(int *A,int *B,ll *C){
		FFTinit(200000);
		cerr<<LEN<<endl;
		For(i,0,LEN-1) a[i]=COMPLEX(A[i],B[i]);
		DFT(a,LEN);
		cerr<<LEN<<endl;
		For(i,0,LEN-1){
			int ano=(LEN-i)&(LEN-1);
			COMPLEX v1=(a[i]+a[ano].conj())*COMPLEX(0.5,0);
			COMPLEX v2=(a[i]-a[ano].conj())*COMPLEX(0,-0.5);
			b[ano]=v1*v2;
		}
		DFT(b,LEN);
		cerr<<LEN<<endl;
		For(i,0,200000)
			C[i]+=(ll)(b[i].r/LEN+0.49);
	}
};

int main(){
	MTT::FFTpre();
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	
	For(i,1,n) ++A[a[i]];
	For(i,1,n-1) ++B[min(a[i],a[i+1])];
	For(i,1,n-1) ++C[max(a[i],a[i+1])];
	For(i,1,m) ++D[b[i]];
	For(i,1,m-1) ++E[min(b[i],b[i+1])];
	For(i,1,m-1) ++F[max(b[i],b[i+1])];
	
	cerr<<233<<endl;
	MTT::Mult(A,D,p1);
	MTT::Mult(A,E,e1);
	MTT::Mult(B,D,e1);
	MTT::Mult(B,E,f1);
	
	cerr<<233<<endl;
	MTT::Mult(A,D,p2);
	MTT::Mult(A,F,e2);
	MTT::Mult(C,D,e2);
	MTT::Mult(C,F,f2);
	
	For(i,1,200000){
		p1[i]+=p1[i-1];
		e1[i]+=e1[i-1];
		f1[i]+=f1[i-1];
	}
	Rep(i,199999,0){
		p2[i]+=p2[i+1];
		e2[i]+=e2[i+1];
		f2[i]+=f2[i+1];
	}
	
	while (Q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",(p2[x]-e2[x]+f2[x])-(p1[x-1]-e1[x-1]+f1[x-1]));
	}
}