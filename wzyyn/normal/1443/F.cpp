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
const int N=200005;
int ans,n,k,p[N];
int a[N],b[N],vi[N],pr[N],nx[N];
void Del(int x){
	pr[nx[x]]=pr[x];
	nx[pr[x]]=nx[x];
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	For(i,1,k) scanf("%d",&b[i]),b[i]=p[b[i]];
	For(i,1,n) vi[i]=0;
	For(i,1,k) vi[b[i]]=1;
	vi[0]=vi[n+1]=1;
	For(i,0,n) nx[i]=i+1,pr[i+1]=i;
	int ans=1;
	For(i,1,k){
		int f1=vi[pr[b[i]]];
		int f2=vi[nx[b[i]]];
		if (f1&&f2) return puts("0"),void(0);
		if (f1) Del(nx[b[i]]);
		if (f2) Del(pr[b[i]]);
		if (!f1&&!f2) Del(pr[b[i]]),ans=2ll*ans%998244353;
		vi[b[i]]=0;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}