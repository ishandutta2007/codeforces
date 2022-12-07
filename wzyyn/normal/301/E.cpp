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
const int mo=1000000007;
int n,m,K,ans,C[105][105];
int f[55][55][55][105];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	For(i,0,100) C[i][0]=1;
	For(i,1,100) For(j,1,i)
		C[i][j]=min(101,C[i-1][j]+C[i-1][j-1]);
	n/=2;
	For(i,1,n) f[1][i][i][1]=1;
	For(v,1,min(m,n+1)){
		For(j,1,n) For(way,1,K)
			UPD(ans,f[v][0][j][way]*1ll*(m+1-v)%mo);
		For(j,1,n) For(la,1,j) For(no,0,n-j)
			For(way,1,K/C[la+no-1][la-1])
				UPD(f[v+1][no][j+no][way*C[la+no-1][la-1]],f[v][la][j][way]);
	}
	printf("%d\n",ans);
}