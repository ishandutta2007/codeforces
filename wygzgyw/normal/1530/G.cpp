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
const int maxn=2010;
int T,n,k,cnt;
char a[maxn],b[maxn],s[maxn],t[maxn];
vector<pair<int,int> > res,ans;
int p[maxn],all;
void init() {
	all=0; for (int i=1;i<=n;i++) if (s[i]=='1') p[++all]=i; p[++all]=n+1;
}
void add(int l,int r) { reverse(s+l,s+r+1); res.push_back(MP(l,r)); }
void solve() {
	res.clear();
	if (k==cnt) {
		for (int I=1;I<=2;I++) {
			init();
			memcpy(t,s,sizeof(char)*(n+4));
			reverse(t+p[1],t+n+1);
			int flag=0;
			for (int i=1;i<=n;i++) if (t[i]!=s[i]) { flag=(t[i]<s[i]); break; }
			if (flag) memcpy(s,t,sizeof(char)*(n+4)),res.push_back(MP(p[1],n));
		}
		return;
	}
	init();
	for (int i=all;i>k+2;i--) {
		add(p[i-k],p[i]-1); init();
	}
	if (k&1) {
		for (int i=1;i<=k+1;i++) {
			add(p[1],p[k+1]-1); init();
			add(p[1]+1,p[k+2]-1); init();
		}
	} else {
		for (int i=1;i<=k+1;i++) {
			add(p[1],p[k+1]-1); init();
			add(p[1]+1,p[k+1]); init();
		}
	}
}
int main() {
	read(T); while (T--) {
		read(n),read(k);
		scanf("%s",a+1); scanf("%s",b+1);
		int flag=1; for (int i=1;i<=n;i++) flag&=(a[i]==b[i]); if (flag) { puts("0"); continue; }
		cnt=0; flag=0; for (int i=1;i<=n;i++) cnt+=(a[i]=='1'),flag+=(a[i]=='1')-(b[i]=='1');
		if (flag!=0||!k||cnt<k) { puts("-1"); continue; }
		memcpy(s,a,sizeof(char)*(n+4)); solve(); memcpy(a,s,sizeof(char)*(n+4));
		ans=res;
		memcpy(s,b,sizeof(char)*(n+4)); solve(); memcpy(b,s,sizeof(char)*(n+4));
		flag=1; for (int i=1;i<=n;i++) flag&=(a[i]==b[i]); if (!flag) { puts("-1"); continue; }
		printf("%d\n",(int)ans.size()+(int)res.size());
		for (pair<int,int> &A : ans) printf("%d %d\n",A.first,A.second);
		reverse(res.begin(),res.end());
		for (pair<int,int> &A : res) printf("%d %d\n",A.first,A.second);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/