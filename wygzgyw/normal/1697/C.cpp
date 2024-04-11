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
typedef long long ll;
const int maxn=(1e5)+10;
int T,n;
char s[maxn],t[maxn];
vector<char> A,B;
int cnt[3];
int bel[maxn],L[maxn],R[maxn],id[maxn],dy[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++,cnt[t[i]-'a']--;
		if (cnt[0]!=0||cnt[1]!=0||cnt[2]!=0) { puts("NO"); continue; }
		A.clear(),B.clear();
		for (int i=1;i<=n;i++) if (s[i]!='b') A.push_back(s[i]);
		for (int i=1;i<=n;i++) if (t[i]!='b') B.push_back(t[i]);
		bool flag=1;
		for (int i=0;i<A.size();i++) flag&=(A[i]==B[i]);
		if (!flag) { puts("NO"); continue; }
		int tot=0,C=0;
		for (int i=1;i<=n;i++) {
			if (t[i]!='b') C++; else tot++,bel[tot]=C;
		}
		tot=C=0;
		int lst=0;
		for (int i=1;i<=n;i++) {
			if (s[i]!='b') C++,id[i]=C;
			if (s[i]=='c') lst=id[i];
			if (s[i]=='b') tot++,L[tot]=lst,dy[i]=tot;
		}
		//for (int i=1;i<=n;i++) if (s[i]=='b') printf("??%d\n",i);
		lst=C+1;
		for (int i=n;i>=1;i--) {
			if (s[i]=='a') lst=id[i];
			if (s[i]=='b') R[dy[i]]=lst-1;
		}
		flag=1;
		for (int i=1;i<=tot;i++) flag&=(L[i]<=bel[i]&&bel[i]<=R[i]);
	//	for (int i=1;i<=tot;i++) printf("%d %d %d\n",L[i],bel[i],R[i]);
		if (flag) puts("YES"); else puts("NO");
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