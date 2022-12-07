#include<bits/stdc++.h>

using namespace std;

const int N=200005;
const int mo=1000000007;
int n,a[N],id[N];
int t[N],f[N],g[N],h[N];
bool cmp(int x,int y){
	return a[x]==a[y]?x>y:a[x]<a[y];
}
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]=(t[x]+v)%mo;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s=(s+t[x])%mo;
	return s;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++) a[id[i]]=i;
	for (int i=1;i<=n;i++) t[i]=0;
	for (int i=1;i<=n;i++){
		f[i]=(ask(a[i])+1)%mo;
		change(a[i],f[i]);
	}
	for (int i=1;i<=n;i++) t[i]=0;
	for (int i=n;i>=1;i--){
		g[i]=(ask(n-a[i]+1)+1)%mo;
		change(n-a[i]+1,g[i]);
	}
	int p=0,ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+1ll*f[i]*g[i])%mo;//cout<<f[i]<<' '<<g[i]<<endl;
	for (int i=1;i<=n;i++) t[i]=0;
	for (int i=n;i>=1;i--)
		if (a[i]>=p){
			for (int j=a[i];j>p;j--){
				if (j==a[i]) h[id[j]]=g[id[j]];
				else h[id[j]]=(ask(n)+mo-ask(id[j]))%mo;
				ans=(ans+mo-1ll*f[id[j]]*h[id[j]]%mo)%mo;
				//cout<<j<<' '<<id[j]<<' '<<h[id[j]]<<endl;
				change(id[j],h[id[j]]);
			}
			for (int j=a[i];j>p;j--)
				change(id[j],mo-h[id[j]]);
			p=a[i];
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}