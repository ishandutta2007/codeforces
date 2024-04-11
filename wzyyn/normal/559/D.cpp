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
const int N=100005;
double p[N],ans;
int n,x[N],y[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
double F(int a,int b){
	return 1.0*x[a]*y[b]-1.0*y[a]*x[b]-
		   gcd(abs(x[a]-x[b]),abs(y[a]-y[b]));
}
int main(){
	p[0]=1;
	scanf("%d",&n);
	For(i,1,n) p[i]=p[i-1]*0.5;
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n)
		for (int j=i%n+1,k=2;j!=i&&k<=100;j=j%n+1,k++)
			ans+=(p[k]-p[n])*F(i,j);
	ans/=1.0-p[n]*(1+n+n*(n-1)/2);
	printf("%.10lf\n",0.5*ans+1);
}