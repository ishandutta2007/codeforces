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
const int N=3005,M=305;
double a[N][M],f[M][N];
double S[M],ans;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m)
		scanf("%lf",&a[i][j]),a[i][j]*=0.001;
	For(i,1,m){
		double p=1;
		For(j,1,n){
			S[i]+=p*a[j][i];
			f[i][j]=p*a[j][i];
			p*=(1-a[j][i]);
		}
	}
	For(i,1,n){
		int p=1;
		For(j,1,m)
			if (S[j]>S[p])
				p=j;
		ans+=S[p];
		double pp=S[p]=0;
		For(j,1,n){
			S[p]+=pp*a[j][p];
			double tmp=pp*a[j][p];
			pp=pp*(1-a[j][p])+f[p][j];
			f[p][j]=tmp;
		}
	}
	printf("%.10lf\n",ans);
}