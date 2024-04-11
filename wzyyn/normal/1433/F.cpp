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
int n,m,k,f[75],g[75];
int ff[75][75],gg[75][75];
void update(){
	memset(ff,233,sizeof(ff));
	ff[0][0]=0;
	For(i,1,m){
		memcpy(gg,ff,sizeof(gg));
		int x;
		scanf("%d",&x);
		For(j,0,m/2) For(p,0,k-1)
			ff[j+1][(p+x)%k]=max(ff[j+1][(p+x)%k],gg[j][p]+x);
	}
	For(j,0,m/2) For(p,0,k-1)
		ff[0][p]=max(ff[0][p],ff[j][p]);
	memcpy(g,f,sizeof(g));
	For(i,0,k-1) For(j,0,k-1)
		f[(i+j)%k]=max(f[(i+j)%k],g[i]+ff[0][j]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(f,233,sizeof(f));
	f[0]=0;
	For(i,1,n) update();
	printf("%d\n",f[0]);
}