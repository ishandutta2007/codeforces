#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
int n,a[1005][1005];
int b[1005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	int G=gcd(a[1][n],a[2][n]);
	int p=a[1][n]/G,q=a[2][n]/G;
	int v=a[1][2]/p/q;
	for (;b[1]*b[1]!=v;++b[1]);
	b[1]*=p;
	For(i,2,n) b[i]=a[1][i]/b[1];
	For(i,1,n) printf("%d ",b[i]);
}