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
const int maxn=(2e5)+10;
int T,n;
int a[maxn];
ll ans;
int st[maxn],tot,L[maxn],R[maxn];
char s[maxn];
pair<int,int> p[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='('?1:-1);
		for (int i=0;i<=n;i++) p[i]=MP(a[i],i);
		sort(p,p+n+1);
		for (int i=1;i<=n;i++) {
			ans+=(ll)p[i].first*i;
		}
		for (int i=0;i<=n;i++) ans+=a[i];
		tot=0;
		for (int i=0;i<=n;i++) {
			while (tot&&a[st[tot]]>a[i]) tot--;
			L[i]=(tot==0?-1:st[tot]),st[++tot]=i;
		}
		tot=0;
		for (int i=n;i>=0;i--) {
			while (tot&&a[st[tot]]>=a[i]) tot--;
			R[i]=(tot==0?n+1:st[tot]),st[++tot]=i;
		}
		for (int i=0;i<=n;i++) {
			ans-=(ll)a[i]*(i-L[i])*(R[i]-i);
		}
		printf("%lld\n",ans); ans=0;
	}
	return 0;
}