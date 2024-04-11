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
const int maxn=(1e5)+10;
int T;
char s[maxn];
int t[maxn];
int cnt[30],N;
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1); int n=strlen(s+1);
		memset(cnt,0,sizeof(cnt)); int flag=1;
		for (int i=1;i<=n;i++) flag&=(s[i]==s[1]),cnt[s[i]-'a']++;
		if (flag) { printf("%s\n",s+1); continue; }
		int fd=-1;
		for (int i=0;i<26;i++) if (cnt[i]==1) { fd=i; break; }
		if (fd!=-1) {
			printf("%c",fd+'a');
			for (int i=0;i<26;i++) if (i!=fd) {
				for (int j=0;j<cnt[i];j++) printf("%c",i+'a');
			}
			puts(""); continue;
		}
		N=0;
		for (int i=0;i<26;i++) if (cnt[i]) t[++N]=i;
		if (cnt[t[1]]<=n-cnt[t[1]]+2) {
			printf("%c%c",t[1]+'a',t[1]+'a'); cnt[t[1]]-=2;
			for (int i=2;i<=N;i++) for (int j=1;j<=cnt[t[i]];j++) {
				printf("%c",t[i]+'a');
				if (cnt[t[1]]-->0) printf("%c",t[1]+'a');
			}
			puts(""); continue;
		}
		if (N==2) {
			printf("%c",t[1]+'a');
			for (int i=1;i<=cnt[t[2]];i++) printf("%c",t[2]+'a');
			for (int i=1;i<cnt[t[1]];i++) printf("%c",t[1]+'a');
			puts(""); continue;
		}
		printf("%c%c",t[1]+'a',t[2]+'a'); cnt[t[2]]--;
		for (int i=1;i<cnt[t[1]];i++) printf("%c",t[1]+'a');
		printf("%c",t[3]+'a'); cnt[t[3]]--;
		for (int i=2;i<=N;i++) for (int j=1;j<=cnt[t[i]];j++) printf("%c",t[i]+'a');
		puts("");
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