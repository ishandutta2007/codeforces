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

const int N=355;
const int mo=1000000007;
int n,m,x,f[N][N],g[N][N];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233; 
}
int main(){
	scanf("%d%d%d",&m,&n,&x);
	if (n<m) return puts("0"),0;
	f[0][0]=1;
	For(i,1,n){
		For(j,0,m) For(k,0,j) g[j][k]=(i==x?0:f[j][k]);
		For(j,0,m) For(k,0,j) UPD(g[j+1][k+1],f[j][k]);
		For(j,0,m) For(k,0,j) f[j][k]=g[j][k];
		For(j,0,m) For(k,1,j) UPD(f[j][k-1],g[j][k]);
	}
	int ans=f[m][0];
	For(i,1,m) ans=1ll*ans*i%mo;
	printf("%d\n",ans);
}