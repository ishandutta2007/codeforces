#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,cnt[3],a[maxn],b[maxn];
bool flag;
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		flag=1;
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[a[i]+1]++;
		for (int i=n;i>=1;i--) {
			cnt[a[i]+1]--;
			b[i]-=a[i];
			if (b[i]>0&&!cnt[2]) { flag=0; break; }
			if (b[i]<0&&!cnt[0]) { flag=0; break; }
		}
		if (!flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/