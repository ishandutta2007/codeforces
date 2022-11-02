// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef unsigned long long ull;
const ull M=233333;
const int maxn=(2e5)+10;
int T,n,m,q;
int s[maxn]; char S[maxn]; ull mi[maxn],H[maxn];
int v(int l,int r) { return (s[r]-s[l-1])%9; }
ull query(int l,int r) {
	return (H[r]-H[l-1])*mi[n-r];
}
int L1[10],L2[10];
int main() {
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=mi[i-1]*M;
	read(T);
	while (T--) {
		scanf("%s",S+1),n=strlen(S+1),read(m),read(q);
		
		for (int i=1;i<=n;i++) s[i]=s[i-1]+S[i]-'0';
		for (int i=1;i<=n;i++) H[i]=H[i-1]+mi[i]*(S[i]-'0'+1);
		for (int i=0;i<9;i++) {
			int &mn=L1[i]; mn=-1;
			for (int j=1;j<=n-m+1;j++) if (v(j,m+j-1)==i) { mn=j; break; }
			if (mn==-1) continue;
			L2[i]=-1;
			for (int j=mn+1;j<=n-m+1;j++) if (v(j,m+j-1)==i) { L2[i]=j; break; }
		}
		while (q--) {
			int l,r; read(l),read(r);
			int k; read(k);
			pair<int,int> ans; ans.first=1e9; ans.second=0;
			for (int i=0;i<9;i++) {
				int j=(k-v(l,r)*i%9+9)%9;
				if (L1[i]==-1||L1[j]==-1) continue;
				if (i==j) { if (L2[i]!=-1) ans=min(ans,MP(L1[i],L2[i])); }
				else ans=min(ans,MP(L1[i],L1[j]));
			}
			if (ans.first==1e9) puts("-1 -1"); else printf("%d %d\n",ans.first,ans.second);
		}
	}
	return 0;
}