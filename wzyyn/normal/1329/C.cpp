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
const int N=1<<21;
int a[N],q[N];
int n,m;
void pop(int k){
	if (!a[k*2]&&!a[k*2+1])
		return a[k]=0,void(0);
	if (a[k*2]>a[k*2+1])
		a[k]=a[k*2],pop(k*2);
	else a[k]=a[k*2+1],pop(k*2+1);
}
int fpop(int k){
	if (!a[k*2]&&!a[k*2+1]) return k;
	if (a[k*2]>a[k*2+1]) return fpop(k*2);
	return fpop(k*2+1);
}
void solve(int k){
	if (k>=(1<<m)){
		for (;a[k];q[++*q]=k,pop(k));
		return;
	}
	for (;fpop(k)>=1<<m;q[++*q]=k,pop(k));
	solve(k*2); solve(k*2+1); 
}
void solve(){
	scanf("%d%d",&n,&m); *q=0;
	For(i,0,(1<<(n+1))-1) a[i]=0;
	For(i,1,(1<<n)-1) scanf("%d",&a[i]);
	solve(1);
	ll ans=0;
	For(i,1,(1<<m)-1) ans+=a[i];
	printf("%lld\n",ans);
	For(i,1,*q) printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}