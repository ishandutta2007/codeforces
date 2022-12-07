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
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if (n==1&&m==1) puts("0");
	else if (n<=m){
		For(i,1,n) For(j,n+1,n+m)
			printf("%d%c",i*j,j==n+m?'\n':' ');
	}
	else{
		For(i,m+1,m+n) For(j,1,m)
			printf("%d%c",i*j,j==m?'\n':' ');
	}
}