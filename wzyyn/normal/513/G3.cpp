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

double f[2][105][105];
int n,K,a[105];
int C2(int x){
	return x*(x+1)/2;
}
int main(){
	scanf("%d%d",&n,&K);
	K=min(K,1000);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) For(j,i+1,n) f[0][i][j]=(a[i]>a[j]);
	For(T,1,K){
		int now=T&1,pre=now^1;
		memset(f[now],0,sizeof(f[now]));
		For(j,1,n) For(k,j+1,n){
			f[now][j][k]=(C2(j-1)+C2(k-j-1)+C2(n-k))*f[pre][j][k];
			For(s,k+1,j+n) f[now][j][k]+=(1-f[pre][s-k][s-j])*(min(j,s-k)-max(1,s-n)+1);
			For(s,j+1,j+k-1) f[now][j][k]+=f[pre][s-j][k]*(min(j,s-j)-max(1,s-k+1)+1);
			For(s,j+k+1,n+k) f[now][j][k]+=f[pre][j][s-k]*(min(k,s-k)-max(j+1,s-n)+1);
			f[now][j][k]/=n*(n+1)/2;
		}
	}
	double ans=0;
	For(j,1,n) For(k,j+1,n) ans+=f[K&1][j][k];
	printf("%.15lf\n",ans); 
}