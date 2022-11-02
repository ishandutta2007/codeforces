#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,a[maxn];
ll sum;
vector<pair<int,int> > ans;
void solve(int x,int y) {
	sum+=(ll)(x-y)*(x-y);
	swap(a[x],a[y]);
	ans.push_back(make_pair(x,y));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) a[i]=i;
		ans.clear();
		sum=0;
		solve(1,n);
		for (int i=2;i<=n/2;i++) solve(n,i);
		for (int i=n/2+1;i<n;i++) solve(1,i);
		printf("%lld\n",sum);
		for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
		printf("%d\n",(int)ans.size());
		for (int i=(int)ans.size()-1;i>=0;i--) printf("%d %d\n",ans[i].second,ans[i].first);
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