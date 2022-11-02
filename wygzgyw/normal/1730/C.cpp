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
int T;
char s[maxn];
int n;
multiset<pair<int,int> > t;
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		t.clear();
		for (int i=1;i<=n;i++) t.insert(MP(s[i]-'0',i));
		int pos=0;
		for (int i=1;i<=n;i++) {
			pair<int,int> A=*t.begin();
			if (A.second) {
				while (pos<A.second) {
					pos++;
					t.erase(t.find(MP(s[pos]-'0',pos)));
					if (pos!=A.second) t.insert(MP(min(s[pos]-'0'+1,9),0));
				}
			} else t.erase(t.find(A));
			printf("%d",A.first);
		} puts("");
	}
	return 0;
}