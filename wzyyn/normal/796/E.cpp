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
const int N=1005;
int n,p,K,S,x;
int va[N],vb[N];
int f[2][N][55][55];
void Mx(int &x,int y){
	x<y?x=y:233;
}
int main(){
	scanf("%d%d%d",&n,&p,&K);
	p=min(p,(n+K-1)/K*2);
	scanf("%d",&S);
	For(i,1,S) scanf("%d",&x),va[x]=1;
	scanf("%d",&S);
	For(i,1,S) scanf("%d",&x),vb[x]=1;
	memset(f,233,sizeof(f));
	f[0][0][0][0]=0;
	int now=0;
	For(i,1,n){
		For(j,0,p) For(k,0,K) For(l,0,K){
			Mx(f[now][j+1][k][K],f[now][j][k][l]);
			Mx(f[now][j+1][K][l],f[now][j][k][l]);
			Mx(f[now][j+2][K][K],f[now][j][k][l]);
		}
		For(j,0,p) For(k,0,K) For(l,0,K)
			f[now^1][j][k][l]=-(1<<30);
		For(j,0,p) For(k,0,K) For(l,0,K)
			Mx(f[now^1][j][k-(k!=0)][l-(l!=0)],f[now][j][k][l]+((k&&va[i])||(l&&vb[i])));
		now^=1;
	}
	int ans=0;
	For(j,0,p) For(k,0,K) For(l,0,K)
		ans=max(ans,f[now][j][k][l]);
	printf("%d\n",ans); 
}