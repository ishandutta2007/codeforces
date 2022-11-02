#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
const int INF=0x7f7f7f7f;
int T,n,cnt,a[maxn],L[maxn],R[maxn],ans;
struct node { int l,r; } d[maxn];
bool cmp(node A,node B) { return A.l>B.l; }
multiset<int> s;
multiset<int>::iterator it;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		cnt=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) cnt++;
			L[i]=R[i]=0;
		}
		int now=0;
		for (int i=1;i<=n;i++) {
			if (a[i]==0) now++;
			else {
				if (now<cnt/2) L[a[i]]=max(L[a[i]],now);
				else R[a[i]]=max(R[a[i]],cnt-now);
			}
		}
		for (int i=1;i<=n;i++) d[i]=(node){L[i],R[i]};
		sort(d+1,d+n+1,cmp);
		//for (int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
		s.clear(); int pos=1;
		ans=0;
		for (int i=cnt/2;i>=1;i--) {
			while (pos<=n&&d[pos].l>=i) {
				s.insert(d[pos].r);
				pos++;
			}
			if (!s.empty()) {
				it=s.begin(); s.erase(it); ans++;
			}
		}
		while (pos<=n) s.insert(d[pos].r),pos++;
		for (int i=cnt/2;i>=1;i--) {
			if (!s.empty()) {
				it=s.end(); it--;
				if ((*it)>=i) { ans++; s.erase(it); }
			}
		}
		printf("%d\n",min(ans,cnt/2));
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