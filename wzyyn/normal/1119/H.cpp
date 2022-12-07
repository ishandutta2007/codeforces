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
const int N=265000;
int n,k,m,A,B,C,S;
int a[N],b[N],c[N];
int cnt[N],v1[N],v2[N],v3[N];
int tmp1[N],tmp2[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void solve(int *a,int *b){
	for (int d=1;d<=m;d<<=1)
		for (int i=0;i<m;i+=(d<<1))
			for (int j=i;j<i+d;j++){
				int x=a[j],y=a[j+d];
				a[j]=x+y,a[j+d]=x-y;
			}
	For(i,0,m)
		b[i]=(n+a[i])/2;
}
void IFWT(int *a){
	for (int d=1;d<=m;d<<=1)
		for (int i=0;i<m;i+=(d<<1))
			for (int j=i;j<i+d;j++){
				int x=a[j],y=a[j+d];
				a[j]=1ll*(x+y)*(mo+1)/2%mo;
				a[j+d]=1ll*(x-y)*(mo+1)/2%mo;
			}
}
int main(){
	scanf("%d%d%d%d%d",&n,&k,&A,&B,&C);
	m=(1<<k)-1;
	For(i,1,n){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		S^=a[i]; b[i]^=a[i]; c[i]^=a[i];
	}
	For(i,0,m) cnt[i]=0;
	For(i,1,n) ++cnt[b[i]];
	solve(cnt,v1);
	For(i,0,m) cnt[i]=0;
	For(i,1,n) ++cnt[c[i]];
	solve(cnt,v2);
	For(i,0,m) cnt[i]=0;
	For(i,1,n) ++cnt[b[i]^c[i]];
	solve(cnt,v3);
	For(i,0,m){
		int V00=(v1[i]+v2[i]+v3[i]-n)/2;
		int V01=v1[i]-V00;
		int V10=v2[i]-V00;
		int V11=v3[i]-V00;
		a[i]=1ll*power((1LL*A+B+C)%mo,V00)
				*power((1LL*A+B-C)%mo,V01)%mo
				*power((1LL*A-B+C)%mo,V10)%mo
				*power((1LL*A-B-C)%mo,V11)%mo;
	}
	IFWT(a);
	For(i,0,m)
		printf("%d ",(a[i^S]%mo+mo)%mo);
}
/*
011
101
110

1->0 -1
*/