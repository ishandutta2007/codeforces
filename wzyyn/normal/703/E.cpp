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
const int N=1005;
const int S=10005;
int n,fr[N][S];
pll f[N][S];
ll k,a[N],b[N],q[S];
map<ll,int> mp;
void identify(){
	for (int i=1;1ll*i*i<=k;i++)
		if (k%i==0) q[++*q]=i,q[++*q]=k/i;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,*q) mp[q[i]]=i;
	//For(i,1,*q) cout<<q[i]<<endl;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%lld",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) b[i]=gcd(a[i],k);
	if (k==1){
		int idd=1;
		For(i,2,n) if (a[i]<a[idd]) idd=i;
		printf("1\n%d\n",idd);
		exit(0);
	}
	identify();
	memset(f,30,sizeof(f)); f[0][1]=pll(0,0);
	For(i,1,n) For(j,1,*q){
		if (f[i-1][j]<f[i][j])
			f[i][j]=f[i-1][j],fr[i][j]=j;
		int nv=mp[q[j]*gcd(k/q[j],b[i])];
		pll nvvv=pll(f[i-1][j].fi+1,f[i-1][j].se+a[i]);
		if (nvvv<f[i][nv])
			f[i][nv]=nvvv,fr[i][nv]=j;
	}
	if (f[n][*q].fi>10000)
		return puts("-1"),0;
	printf("%lld\n",f[n][*q].fi);
	int v=*q;
	Rep(i,n,1){
		if (fr[i][v]!=v)
			printf("%d ",i);
		v=fr[i][v];
	}
}
/*
5 60
2 4 6 5 4
*/