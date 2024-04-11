#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

int n,m,Q,ans;
long long d[605][605];
long long e[605][605];
long long f[605][605];
int main(){
	scanf("%d%d",&n,&m);
	memset(d,30,sizeof(d));
	For(i,1,n) d[i][i]=0;
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x][y]=e[y][x]=v;
		d[x][y]=d[y][x]=v;
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	memset(f,233,sizeof(f));
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		f[x][y]=f[y][x]=v;
	}
	For(i,1,n) For(j,1,n) For(k,1,n)
		f[i][k]=max(f[i][k],f[j][k]-d[i][j]);
	For(i,1,n) For(j,1,n) For(k,1,n)
		f[i][k]=max(f[i][k],f[i][j]-d[j][k]);
	For(i,1,n) For(j,i+1,n)
		if (e[i][j]&&e[i][j]<=f[i][j]) ++ans;
	cout<<ans<<endl;
}