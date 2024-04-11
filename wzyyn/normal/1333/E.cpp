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
int n,nd;
int ans[505][505];
int main(){
	scanf("%d",&n);
	if (n<=2) return puts("-1"),0;
	int fl=0,m=n;
	for (;m>3;m--,fl^=1)
		if (!fl){
			For(j,1,m) ans[j][m]=++nd;
			Rep(j,m-1,1) ans[m][j]=++nd;
		}
		else{
			For(j,1,m) ans[m][j]=++nd;
			Rep(j,m-1,1) ans[j][m]=++nd;
		}
	ans[1][1]=++nd; ans[1][2]=++nd; ans[2][2]=++nd;
	ans[3][2]=++nd; ans[3][1]=++nd; ans[1][3]=++nd;
	ans[2][3]=++nd; ans[3][3]=++nd; ans[2][1]=++nd;
	For(i,1,n) For(j,1,n)
		printf("%d%c",ans[i][j],j==n?'\n':' ');
}
/*
1 2 6
9 3 7
5 4 8
*/