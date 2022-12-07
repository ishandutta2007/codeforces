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
double a[1005][60];
double b[1005][60];
double f[1005][60];
int n;
double p;
double solve(int n){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(f,0,sizeof(f));
	For(i,1,n){
		a[i][1]=p; a[i][2]=1-p; b[i][2]=1;
		For(j,1,55){
			a[i][j]+=a[i][j-1]*a[i-1][j-1];
			b[i][j]+=b[i][j-1]*a[i-1][j-1];
		}
	}
	f[1][1]=p*(1-p);
	For(i,2,50) f[1][i]=a[n][i]-a[n][i+1];
	For(i,2,n) For(j,1,50)
		if (j==1){
			For(k,2,50)
				f[i][k]+=f[i-1][j]*(b[n-i+1][k]-b[n-i+1][k+1]);
		}
		else if (j==2){
			f[i][1]+=f[i-1][2];
		}
		else if (i==n){
			For(k,1,j-1) f[i][k]+=f[i-1][j]*a[1][k];
		}
		else{
			For(k,1,j-1){
				double pp=a[n-i+1][k]-a[n-i+1][k+1];
				if (k==1) pp=p*(1-p);
				f[i][k]+=f[i-1][j]*pp/(1-a[n-i+1][j]);
			}
		}
	double ans=0;
	For(i,1,n) For(j,1,50){
		//cout<<i<<' '<<j<<' '<<f[i][j]<<endl; 
		ans+=f[i][j]*j;
	}
	return ans;
}
int main(){
	scanf("%d%lf",&n,&p);
	p/=1e9;
	if (n==1){
		printf("%.15lf\n",2-p);
		return 0;
	}
	if (n<=1000){
		printf("%.15lf\n",solve(n));
		return 0;
	}
	double v1=solve(1000);
	double v2=solve(999);
	//cout<<v1<<' '<<v2<<endl;
	printf("%.15lf\n",v1+(v1-v2)*(n-1000));
}