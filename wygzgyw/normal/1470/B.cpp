#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxm=(1e6)+10;
const int maxn=(3e5)+10;
int T,n,a[maxn],tmp;
bool vis[maxm];
int tot,prime[maxm];
map<int,int> cnt;
int q,mx,sum;
ll x;
int c1;
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=2;i<maxm;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			tmp=prime[j]*i;
			if (tmp>=maxm) break;
			vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	read(T);
	while (T--) {
		read(n);
		cnt.clear();
		for (int i=1;i<=n;i++) {
			read(a[i]);
			for (int j=1;j<=tot&&prime[j]*prime[j]<=a[i];j++) {
				while (a[i]%(prime[j]*prime[j])==0) a[i]/=(prime[j]*prime[j]);
			}
			cnt[a[i]]++;
		}
		mx=0; sum=0; c1=cnt[1];
		for (int i=1;i<=n;i++) if (a[i]!=1) {
			tmp=cnt[a[i]];
			if (!tmp) continue;
			mx=max(mx,tmp);
			if (tmp%2==0) sum+=tmp;
			cnt[a[i]]=0;
		}
		read(q);
		while (q--) {
			read(x);
			if (!x) printf("%d\n",max(mx,c1));
			else {
				printf("%d\n",max(mx,sum+c1));
			}
		}
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