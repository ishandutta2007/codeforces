#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(1e18);
int T,n,ans[60],fa[60];
bool vis[60];
ll k,c[60],dp[60],tmp,x;
ll mul(ll x,ll y) {
	if (!x||!y) return 0;
	if (x>INF/y) return INF;
	return x*y;
}
int find(int x) {
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x); y=find(y); fa[x]=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	c[1]=c[2]=1;
	for (int i=3;i<=50;i++) c[i]=mul(c[i-1],i-2);
	dp[0]=1;
	for (int i=1;i<=50;i++) {
		for (int j=1;j<=i;j++) {
			dp[i]+=mul(dp[i-j],c[j]);
			if (dp[i]>INF) dp[i]=INF;
		}
	}
	read(T);
	while (T--) {
		read(n);
		read(k);
		if (dp[n]<k) { printf("-1\n"); continue; }
		int i=0,j;
		for (int i=0;i<n;i++) fa[i]=i,vis[i]=0;
		k--;
		while (i<n) {
			j=1;
			while (mul(c[j],dp[n-i-j])<=k) {
				k-=mul(c[j],dp[n-i-j]);
				j++;
			}
			//printf("%d %d\n",i,j);
			ans[i]=i+j-1;
			merge(i,ans[i]);
			vis[i+j-1]=1;
			x=k/dp[n-i-j];
			for (int pos=i+1;pos<i+j-1;pos++) {
				for (int v=i;v<i+j;v++) {
					if (vis[v]||find(v)==find(pos)) continue;
					if (c[j-pos+i]<=x) {
						x-=c[j-pos+i];
						continue;
					}
					ans[pos]=v;
					merge(v,pos);
					vis[v]=1;
					break;
				}
			}
			for (int v=i;v<i+j;v++)
				if (!vis[v]) { ans[i+j-1]=v; vis[v]=1; break; }
			k%=dp[n-i-j];
			i+=j;
		}
		for (int i=0;i<n;i++) printf("%d ",ans[i]+1);
		printf("\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/