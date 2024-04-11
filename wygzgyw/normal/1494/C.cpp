#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=2e9;
const int maxn=(2e5)+10;
int T,n,m,a[maxn],b[maxn],ans1,ans2;
int pos,pre[maxn],suf[maxn];
map<int,int> M;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m); M.clear();
		a[0]=-INF,a[n+1]=INF;
		b[0]=-INF,b[m+1]=INF;
		for (int i=1;i<=n;i++) read(a[i]),M[a[i]]++;
		for (int i=1;i<=m;i++) read(b[i]);
		pos=0;
		for (int i=1;i<=n;i++) if (a[i]<0) pos=i;
		
		for (int i=1;i<=m;i++) {
			pre[i]=pre[i-1]+M[b[i]];
		}
		suf[m+1]=0;
		for (int i=m;i>=1;i--) {
			suf[i]=suf[i+1]+M[b[i]];
		}
		
		ans1=ans2=0;
		int x,y;
		for (int i=1;i<=m;i++) {
			if (b[i]<0) {
				x=lower_bound(a+1,a+n+1,b[i])-a;
				if (a[x]>0) continue;
				y=upper_bound(b+1,b+m+1,b[i]+pos-x)-b-1;
				ans1=max(ans1,pre[i-1]+y-i+1);
			} else {
				x=upper_bound(a+1,a+n+1,b[i])-a-1;
				if (a[x]<0) continue;
				y=lower_bound(b+1,b+m+1,b[i]-x+pos+1)-b;
				ans2=max(ans2,suf[i+1]+i-y+1);
			}
		}
		printf("%d\n",ans1+ans2);
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