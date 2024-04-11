#include<bits/stdc++.h>

using namespace std;

const int N=205;
int n,k;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	long long operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}p[N];
int f[N][N];
long long g[N][N];
bool check(long long mid){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=n-2;i>=1;i--)
		for (int j=i+1;j<=n;j++)
			for (int k=i+1;k<j;k++){
				int nf=f[i][k]+f[k][j];
				long long ng=g[i][k]+g[k][j]+abs((p[j]-p[i])*(p[k]-p[i]));
				if (ng>=mid) nf++,ng=0;
				if (nf>f[i][j]||(nf==f[i][j]&&ng>g[i][j]))
					f[i][j]=nf,g[i][j]=ng;
			}
	return f[1][n]>=::k+1;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	long long l=0,r=9e16,ans=0;
	while (l<=r){
		long long mid=(l+r)/2;
		if (check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}