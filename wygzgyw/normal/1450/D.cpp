#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=1e9;
const int maxn=(3e5)+10;
int T,n,a[maxn],cnt[maxn],ans[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) cnt[i]=ans[i]=0; ans[1]=1;
		for (int i=1;i<=n;i++) {
			read(a[i]); cnt[a[i]]++;
			ans[1]&=(cnt[a[i]]==1);
		}
		for (int i=1,l=1,r=n;i<n&&cnt[i];i++) {
			ans[n-i+1]=1;
			if (cnt[i]>1) break;
			if (a[l]==i) l++;
			else {
				if (a[r]==i) r--;
				else break;
			}
		}
		
		for (int i=1;i<=n;i++) printf("%d",ans[i]); puts("");
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