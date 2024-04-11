// author: xay5421
// created: Fri Dec 25 08:05:49 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n;
double p,a[55][55],b[55][55],f[55][55];
struct mat{
	double x[55][55];
	mat operator*(const mat&b)const{
		mat c;
		memset(c.x,0,sizeof(c.x));
		rep(i,0,50)rep(j,0,50)rep(k,0,50)c.x[i][j]+=x[i][k]*b.x[k][j];
		return c;
	}
}A,B,C;
mat po(mat k3,mat k1,int k2){
	for(;k2;k2>>=1,k1=k1*k1)if(k2&1)k3=k3*k1;
	return k3;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%lf",&n,&p);
	p/=1e9;
	a[1][1]=p,a[1][2]=1-p;
	b[1][2]=1-p;
	rep(i,2,50){
		a[i][1]=p,a[i][2]=1-p,b[i][2]=1-p;
		rep(j,2,50){
			a[i][j]+=a[i-1][j-1]*a[i][j-1];
			b[i][j]+=a[i-1][j-1]*b[i][j-1];
		}
	}
	per(i,50,1)rep(j,1,50)a[i][j]*=1-a[i-1][j],b[i][j]*=1-a[i-1][j];
	/*rep(i,1,50)rep(j,1,50){
		D("a[%d][%d]=%.5f %.5f\n",i,j,a[i][j],b[i][j]);
	}*/
	f[1][1]=1,f[1][2]=2;
	rep(i,2,50){
		rep(j,1,50){
			if(j==1){
				double fz=0,fm=0;
				rep(k,1,50)fz+=f[i-1][k]*b[i-1][k],fm+=b[i-1][k];
				//D("1 i=%d j=%d\n",i,j);
				assert(fabs(fm)>1e-10);
				f[i][j]=j+fz/fm;
			}else{
				double fz=0,fm=0;
				rep(k,1,j-1)fz+=f[i-1][k]*a[i-1][k],fm+=a[i-1][k];
				//D("2 i=%d j=%d\n",i,j);
				assert(fabs(fm)>1e-10);
				f[i][j]=j+fz/fm;
			}
		}
	}
	if(n<=50){
		double res=0;
		rep(i,1,n+1)res+=f[n][i]*a[n][i];
		printf("%.20f\n",res);
		return 0;
	}
	A.x[0][0]=1;
	rep(j,1,50){
		if(j==1){
			double fm=0;
			rep(k,1,50){
				fm+=b[50][k];
			}
			rep(k,1,50){
				A.x[k][j]+=b[50][k]/fm;
			}
		}else{
			double fm=0;
			rep(k,1,j-1){
				fm+=a[50][k];
			}
			rep(k,1,j-1){
				A.x[k][j]+=a[50][k]/fm;
			}
		}
		A.x[0][j]=j;
	}
	memset(B.x,0,sizeof(B.x));
	B.x[0][0]=1;
	rep(i,1,50)B.x[0][i]=f[50][i];
	C=po(B,A,n-50);
	//rep(i,0,10)rep(j,0,10)D("%.3f%c",B.x[i][j],j==10?'\n':' ');
	double res=0;
	rep(i,1,50){
		res+=C.x[0][i]*a[50][i];
	}
	printf("%.20f\n",res);
	return 0;
}