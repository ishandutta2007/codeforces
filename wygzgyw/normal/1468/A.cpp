#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int T,n,a[maxn],dp[maxn],tr[maxn];
stack<int> st;
int ans;
void add(int x,int delta) {
	x++;
	for (;x<=n+1;x+=x&(-x)) tr[x]=max(tr[x],delta);
}
int query(int x) {
	int res=-1;
	x++;
	for (;x;x-=x&(-x)) res=max(res,tr[x]);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); int x;
	while (T--) {
		read(n); while (!st.empty()) st.pop(); st.push(0);
		for (int i=1;i<=n+1;i++) tr[i]=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			dp[i]=query(a[i])+1;
			add(a[i],dp[i]);
			while (!st.empty()&&a[st.top()]<=a[i]) {
				x=st.top(); st.pop();
				add(a[x],dp[x]+1);
			}
			st.push(i);
		}
		ans=-1;
		for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%d\n",ans);
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