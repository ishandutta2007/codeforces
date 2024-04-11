#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(2e5)+10;
int n,k1,k2,k3,ans,tmp;
bool vis[maxn];
int s1[maxn],s2[maxn],s3[maxn],mx[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(k1); read(k2); read(k3);
	n=k1+k2+k3; int x;
	for (int i=1;i<=k1;i++) read(x),vis[x]=1;
	for (int i=1;i<=n;i++) s1[i]=s1[i-1]+vis[i];
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=k2;i++) read(x),vis[x]=1;
	for (int i=1;i<=n;i++) s2[i]=s2[i-1]+vis[i];
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=k3;i++) read(x),vis[x]=1;
	for (int i=1;i<=n;i++) s3[i]=s3[i-1]+vis[i];
	mx[n+1]=INF;
	for (int i=n;i>=0;i--)
		mx[i]=min(mx[i+1],s3[i]-s2[i]);
	ans=INF;
	for (int i=0;i<=n;i++) {
		tmp=k1-s1[i]+i-s1[i];
		ans=min(ans,tmp+s2[n]-s3[i]+mx[i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/