#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const ll INF=(1e18);
int n,m;
ll a[maxn],k[maxn],ans[maxn],len[maxn];
set<pair<ll,int> > s1;
set<int> s2;
set<int>::iterator it,it1,it2;
multiset<ll> s3;
multiset<ll>::iterator it3;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	a[n]=-INF;
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=n;i++) s1.insert(make_pair(a[i-1]-a[i]+1,i)),s2.insert(i),s3.insert(1),len[i]=a[i]-a[i-1]-1;
	s2.insert(0);
	for (int i=1;i<=m;i++) read(k[i]);
	pair<ll,int> now; int x,y;
	for (int i=m;i>=1;i--) {
		while (!s1.empty()&&-(*s1.begin()).first>=k[i]) {
			now=*s1.begin();
			it=s2.find(now.second);
			it1=it2=it;
			it1--,it2++;
			x=(*it1),y=(*it2);
			//printf("%d %d %d\n",now.second,x,y);
			s3.erase(y-(*it)),s3.erase((*it)-x),s3.insert(y-x);
			s1.erase(s1.begin());
			s1.erase(make_pair(-len[y],y));
			len[y]=(a[y]-a[x]-1)/(y-x);
			s1.insert(make_pair(-len[y],y));
			s2.erase(now.second);
		}
		it3=s3.end(); it3--;
		ans[i]=*it3;
	}
	for (int i=1;i<=m;i++) printf("%lld ",ans[i]-1); printf("\n");
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