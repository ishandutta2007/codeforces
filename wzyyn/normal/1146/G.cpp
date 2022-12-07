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
const int N=55;
int n,H,m;
int l[N],r[N],x[N],c[N];
int f[N][N][N],S[N][N];
int main(){
	scanf("%d%d%d",&n,&H,&m);
	For(i,1,m) scanf("%d%d%d%d",&l[i],&r[i],&x[i],&c[i]);
	memset(f,233,sizeof(f));
	For(i,0,n) For(j,0,H) f[i+1][i][j]=0;
	//cout<<f[1][1][0]<<endl;
	Rep(i,n,1) For(j,i,n){
		For(k,i,j) For(l,0,H) S[k][l]=0;
		For(p,1,m) if (i<=l[p]&&r[p]<=j)
			For(q,l[p],r[p]) S[q][x[p]+1]-=c[p];
		For(k,i,j) For(l,1,H) S[k][l]+=S[k][l-1];
		For(k,i,j) For(l,0,H)
			f[i][j][l]=max(f[i][j][l],f[i][k-1][l]+f[k+1][j][l]+S[k][l]+l*l);
		For(l,1,H) f[i][j][l]=max(f[i][j][l],f[i][j][l-1]);
	}
	printf("%d ",f[1][n][H]);
}