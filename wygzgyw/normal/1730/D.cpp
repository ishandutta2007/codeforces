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
int T,n;
char s[maxn],t[maxn];

int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		map<pair<int,int>,int> M;
		for (int i=1;i<=n;i++) {
			int x=(s[i]-'a'),y=(t[n-i+1]-'a');
			if (x>y) swap(x,y);
			M[MP(x,y)]++;
		}
		int cnt=0,flag=1;
		for (pair<pair<int,int>,int> A : M) {
			if (A.second%2!=0) flag&=(A.first.first==A.first.second),cnt++;
		}
		if (flag&&cnt<=1) puts("YES"); else puts("NO");
	}
	return 0;
}