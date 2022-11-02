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
const int maxn=(2e5)+10;
int T,n,a,b,c,d;
char s[maxn];
int p1[maxn],p2[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(a),read(b),read(c),read(d);
		scanf("%s",s+1); n=strlen(s+1);
		int c0=0,c1=0;
		for (int i=1;i<=n;i++) if (s[i]=='A') c0++; else c1++;
		if (c0!=a+c+d||c1!=b+c+d) { puts("NO"); continue; }
		int tot=0;
		vector<int> V1,V2;
		for (int i=1;i<n;i++) if (s[i]!=s[i+1]) {
			int j=i;
			while (j<n&&s[j]!=s[j+1]) j++;
			if (s[i]==s[j]) {
				tot+=(j-i+1)/2;
			} else {
				tot+=(j-i+1)/2-1;
				if (s[i]=='B') V2.push_back((j-i+1)/2);
				else V1.push_back((j-i+1)/2);
			}
			i=j;
		}
		sort(V1.begin(),V1.end()),sort(V2.begin(),V2.end());
		if (tot<c+d) {
			int rst=c+d-tot;
			for (int i=0;i<V1.size();i++) p1[i]=(i?p1[i-1]:0)+V1[i];
			for (int i=0;i<V2.size();i++) p2[i]=(i?p2[i-1]:0)+V2[i];
			int flag=0;
			for (int i=0;i<=rst&&i<=(int)V1.size();i++) {
				int sh=rst-i;
				if (sh>(int)V2.size()) continue;
				if ((i==0?0:p1[i-1])<=c&&(sh==0?0:p2[sh-1])<=d) { flag=1; break; }
			}
			if (!flag) { puts("NO"); continue; }
		}
		puts("YES");
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