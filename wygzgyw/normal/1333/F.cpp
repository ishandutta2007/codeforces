#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,tot,prime[maxn];
bool vis[maxn];
int tmp,cnt[maxn],ans[maxn],p[maxn];
int tr[maxn];
void add(int x) {
	for (;x<=n;x+=x&(-x)) tr[x]++;
}
int query(int x) {
	int res=0;
	for (;x;x-=x&(-x)) res+=tr[x];
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=2;i<=n;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=i*2;j<=n;j+=i) p[j]=max(p[j],i);
		for (int j=1;j<=tot;j++) {
			tmp=prime[j]*i;
			if (tmp>n) break;
			vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	//for (int i=1;i<=n;i++) printf("%d ",p[i]); printf("\n");
	int pos=tot+1;
	for (int i=n;i>=1;i--) {
		while (pos>1&&prime[pos-1]>i) pos--;
		cnt[i]=i+tot-pos+1+query(i);
		//printf("%d %d %d %d\n",i,tot-pos+1,query(i),cnt[i]);
		if (p[i]) add(p[i]);
	}
	for (int i=1;i<=n;i++) ans[i]=n+1;
	for (int i=1;i<=n;i++) ans[cnt[i]]=min(ans[cnt[i]],i);
	for (int i=n-1;i>=2;i--) ans[i]=min(ans[i],ans[i+1]);
	for (int i=2;i<=n;i++) printf("%d ",ans[i]); printf("\n");
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