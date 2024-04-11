#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,cnt;
char s[maxn],a[maxn],b[maxn];
bool check(char *t) {
	int now=0;
	for (int i=1;i<=n;i++) {
		if (t[i]=='(') now++;
		else now--;
		if (now<0) return 0;
	}
	if (now!=0) return 0;
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); scanf("%s",s+1);
		int c0=0,c1=0,lst=0; cnt=0;
		for (int i=1;i<=n;i++) if (s[i]=='1') c1++; else c0++;
		if (c1&1) { puts("NO"); continue; }
		for (int i=1;i<=n;i++) {
			if (s[i]=='0') {
				if (lst) a[lst]='(',a[i]=')',lst=0;
				else lst=i;
			} else {
				cnt++;
				if (cnt<=c1/2) a[i]='(';
				else a[i]=')';
			}
		}
		for (int i=1;i<=n;i++) if (s[i]=='1') b[i]=a[i]; else b[i]='('+')'-a[i];
		if (check(a)&&check(b)) {
			puts("YES");
			a[n+1]=b[n+1]=0;
			printf("%s\n%s\n",a+1,b+1);
		} else puts("NO");
	}
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