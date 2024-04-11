#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,k,a[N],now[N],f[N],val[N],g[N],ans;
inline int calc(int x,int y){
	int k1=x/y,k2=k1+1;
	return k1*k1*(y-x%y)+k2*k2*(x%y);
}
inline void down(int x){
	int i=x;
	if (x*2<=n&&val[f[x*2]]>val[f[x]])i=x*2;
	if (x*2<n&&val[f[x*2+1]]>val[f[i]])i=x*2+1;
	if (i!=x){
		swap(f[x],f[i]);
		swap(g[f[x]],g[f[i]]);
		down(i);
	}
}
signed main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ans+=a[i]*a[i];
		now[i]=1;
		f[i]=g[i]=i;
		val[i]=a[i]==now[i]?0:calc(a[i],now[i])-calc(a[i],now[i]+1);
	}
	for (int i=n;i;i--)down(i);
	k-=n;
	while (k--){
		int v=f[1];
		ans-=val[v];
		now[v]++;
		val[v]=a[v]==now[v]?0:calc(a[v],now[v])-calc(a[v],now[v]+1);
		down(1);
	}
	printf("%lld\n",ans);
}