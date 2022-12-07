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
const int mo=998244353;
const int N=200005;
const int M=3005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
int a[N],w[N],v[2*M];
int n,m,s1,s2,f[2][2*M];
int p1[M],p2[M];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		scanf("%d",&w[i]);
		if (!a[i]) s1+=w[i];
		else s2+=w[i];
	}
	For(i,0,2*m)
		v[i]=power(s1+s2+i-m,mo-2);
	f[0][m]=1;
	For(i,0,m-1){
		For(j,m-i-1,m+i+1) f[1][j]=0;
		For(j,m-i,m+i){
			int v1=(m+i-j)/2,v2=(j-(m-i))/2;
			int p1=1ll*(s1+mo-v1)*v[j]%mo;
			int p2=1ll*(s2+v2)*v[j]%mo;
			f[1][j-1]=(f[1][j-1]+1ll*f[0][j]*p1)%mo;
			f[1][j+1]=(f[1][j+1]+1ll*f[0][j]*p2)%mo;
		}
		For(j,m-i-1,m+i+1) f[0][j]=f[1][j];
	}
	int ans1=1,ans2=1;
	int IV1=power(s1,mo-2);
	int IV2=power(s2,mo-2);
	For(i,0,m){
		int p1=f[0][2*(m-i)],p2=f[0][2*i];
		ans1=(ans1+mo-1ll*IV1*i%mo*p1%mo)%mo;
		ans2=(ans2+1ll*IV2*i%mo*p2)%mo;
	}
	For(i,1,n)
		if (a[i]==0)
			printf("%d\n",1ll*ans1*w[i]%mo);
		else
			printf("%d\n",1ll*ans2*w[i]%mo);
}