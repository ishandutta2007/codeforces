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
int T,n,len[maxn];
char s[maxn][4];
vector<int> p2[30*30],p3[30*30*30];
bool query(vector<int> &A,int l,int r) {
	if ((int)A.size()==0||l>r) return 0;
	int x=lower_bound(A.begin(),A.end(),l)-A.begin();
	if (x!=(int)A.size()&&A[x]<=r) return 1;
	return 0;
}
bool solve() {
	int a,b,c;
	for (int i=1;i<=n;i++) {
		len[i]=strlen(s[i]+1);
		if (len[i]==1) {
			return 1;
		} else if (len[i]==2) {
			a=s[i][1]-'a',b=s[i][2]-'a';
			if (a==b) return 1;
			if ((int)p2[b*26+a].size()) return 1;
			p2[a*26+b].push_back(i);
		} else {
			a=s[i][1]-'a',b=s[i][2]-'a',c=s[i][3]-'a';
			if (a==c) return 1;
			if ((int)p3[c*26*26+b*26+a].size()) return 1;
			p3[a*26*26+b*26+c].push_back(i);
		}
	}
	for (int i=1;i<=n;i++) {
		if (len[i]==3) {
			a=s[i][1]-'a',b=s[i][2]-'a',c=s[i][3]-'a';
			if (query(p2[c*26+b],1,i-1)) return 1;
			if (query(p2[b*26+a],i+1,n)) return 1;
		}
		
	}
	return 0;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for (int i=0;i<26*26;i++) p2[i].clear();
		for (int i=0;i<26*26*26;i++) p3[i].clear();
		if (solve()) puts("YES");
		else puts("NO");
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