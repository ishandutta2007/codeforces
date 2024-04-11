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
const int N=405;
int f[N][N],q[N],n,m;
double ans,b[N],c[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,n)
		f[i][j]=(i==j?0:1<<20);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=1;
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	For(i,1,n){
		double val=0;
		For(j,0,n-1){
			double mxv=0;
			For(k,1,n) b[k]=0;
			For(k,1,n) if (f[i][k]==j){
				mxv=1; int sum=0;
				For(l,1,n) if (f[k][l]==1) ++sum;
				For(l,1,n) if (f[k][l]==1) b[l]+=1.0/sum;
			}
			*q=0;
			For(k,1,n)
				if (fabs(f[i][k]-j)<=1)
					q[++*q]=k;
			For(k,1,n){
				double sum=0;
				For(l,1,*q)
					if (b[q[l]]>c[f[k][q[l]]]){
						sum-=c[f[k][q[l]]];
						sum+=(c[f[k][q[l]]]=b[q[l]]);
					}
				mxv=max(mxv,sum);
				For(l,1,*q)
					c[f[k][q[l]]]=0;
			}
			val+=mxv;
		}
		ans=max(ans,val/n);
	}
	printf("%.10lf\n",ans);
}