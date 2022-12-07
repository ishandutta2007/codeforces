#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,nd,ans[1005][1005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i+=4)
		for (int j=1;j<=n;j+=4)
			For(k,0,3) For(l,0,3) ans[i+k][j+l]=nd++;
	For(i,1,n){
		For(j,1,n)
			printf("%d ",ans[i][j]);
		puts(""); 
	}
}