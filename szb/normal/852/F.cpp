#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,A,lsg,a[1001000],N[1001000],p,b[1001000],c[1001000],ys[1001000][25],f[25],d,aa[1001000];
int phi(int x){
		int t=x,num=sqrt(x);
		for (int i=2;i<=num;i++)
			if (x%i==0){
				t-=t/i;
				while (x%i==0) x/=i;
			}
		if (x>1) t-=t/x;
		return t;
	}
int ksm(int x,int y){
		if (y==0)return 1;if (y==1)return x;
		int k=ksm(x,y/2);if (y&1)return k*k%lsg*x%lsg;else return k*k%lsg;
	}
int ksm1(int x,int y){
		if (y==0)return 1;if (y==1)return x;
		int k=ksm1(x,y/2);if (y&1)return k*k%p*x%p;else return k*k%p;
	}
int C(int x,int y){
		int kk=a[x]*N[y]%lsg*N[x-y]%lsg;
		for (int i=1;i<=d;i++)(kk*=ksm(f[i],ys[x][i]-ys[y][i]-ys[x-y][i]))%=lsg;
		return kk;
	}
void doit(int x){
		for (int i=2;i*i<=x;i++)
			if (x%i==0){
				f[++d]=i;while (x%i==0)x/=i;
			}
		if (x!=0)f[++d]=x;
	}
signed main(){
	cin>>n>>m>>A>>p;lsg=phi(p);doit(lsg);
	a[0]=1;for (int i=1;i<=m;i++){
			int kk=i;for (int j=1;j<=d;j++){
					ys[i][j]=ys[i-1][j];
					while (kk%f[j]==0)ys[i][j]++,kk/=f[j];
				}
			a[i]=(a[i-1]*kk)%lsg;aa[i]=kk;
		}
	N[m]=ksm(a[m],phi(lsg)-1);for (int i=m-1;i>=0;i--)N[i]=N[i+1]*(aa[i+1])%lsg;
	for (int i=1;i<=n;i++){
			if (i-1<=m)b[i]=(b[i-1]+C(m,i-1))%lsg;
				else b[i]=b[i-1];
			c[n-i+1]=ksm1(A,b[i]);
		}
	for (int i=1;i<=n;i++)printf("%lld ",c[i]);
}