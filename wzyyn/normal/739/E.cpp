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
const int N=2005;
int n,a,b;
double pa[N],pb[N];
double f[N][N],ans;
int g[N][N];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	For(i,1,n) scanf("%lf",&pa[i]);
	For(i,1,n) scanf("%lf",&pb[i]);
	double l=0,r=1+1e-9;
	For(T,1,50){
		double mid=(l+r)/2;
		For(i,1,n){
			For(j,0,min(i,a)) f[i][j]=0,g[i][j]=0;
			For(k,0,min(i-1,a)){
				double vf; int vg;
				vf=f[i-1][k]+(pb[i]>mid?pb[i]-mid:0);
				vg=g[i-1][k]+(pb[i]>mid?1:0);
				if (vf>f[i][k]) f[i][k]=vf,g[i][k]=vg;
				if (k==a) continue;
				vf=f[i-1][k]+pa[i]+(pb[i]*(1-pa[i])>mid?pb[i]*(1-pa[i])-mid:0);
				vg=g[i-1][k]+(pb[i]*(1-pa[i])>mid?1:0);
				if (vf>f[i][k+1]) f[i][k+1]=vf,g[i][k+1]=vg;
			}
		}
		//printf("%.10lf %.10lf %.10lf %d\n",l,r,f[n][a],g[n][a]);
		//cout<<l<<' '<<r<<' '<<g[n][a]<<endl;
		if (g[n][a]<=b){
			ans=f[n][a]+mid*b;
			r=mid;
		}
		else l=mid;
	}
	printf("%.10lf\n",ans);
}