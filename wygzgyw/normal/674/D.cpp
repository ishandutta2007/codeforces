#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,q;
ll t[maxn],f[maxn],k[maxn];
multiset<ll> val[maxn],all;
ll sum[maxn];
ll query(int x) {
	return sum[x]+t[x]-(k[x]+1)*(t[x]/(k[x]+2));
}
void del_v(int x) {
	if (val[x].empty()) return;
	all.erase(all.find(*val[x].begin()+t[x]/(k[x]+2)));
	all.erase(all.find(*val[x].rbegin()+t[x]/(k[x]+2)));
}
void add_v(int x){
	if (val[x].empty())return;
	all.insert(*val[x].begin()+t[x]/(k[x]+2));
	all.insert(*val[x].rbegin()+t[x]/(k[x]+2));
}
void del(int x) {
	del_v(f[x]);
	val[f[x]].erase(val[f[x]].find(query(x)));
}
void add(int x) {
	val[f[x]].insert(query(x));
	add_v(f[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(t[i]);
	for (int i=1;i<=n;i++) read(f[i]),k[f[i]]++;
	for (int i=1;i<=n;i++) sum[f[i]]+=t[i]/(k[i]+2);
	for (int i=1;i<=n;i++) val[f[i]].insert(query(i));
	for (int i=1;i<=n;i++) add_v(i);
	int op,x,y;
	while (q--) {
		read(op);
		if (op==1) {
			read(x),read(y);
			del(f[f[x]]),del(f[x]);
			if (f[x]!=f[f[f[x]]]) del_v(f[x]);
			sum[f[f[x]]]-=t[f[x]]/(k[f[x]]+2);
			k[f[x]]--;
			sum[f[f[x]]]+=t[f[x]]/(k[f[x]]+2);
			sum[f[x]]-=t[x]/(k[x]+2);
			val[f[x]].erase(val[f[x]].find(query(x)));
			add(f[f[x]]),add(f[x]);
			if (f[x]!=f[f[f[x]]]) add_v(f[x]);
			
			f[x]=y;
			del(f[f[x]]),del(f[x]);
			if (f[x]!=f[f[f[x]]]) del_v(f[x]);
			sum[f[f[x]]]-=t[f[x]]/(k[f[x]]+2);
			k[f[x]]++;
			sum[f[f[x]]]+=t[f[x]]/(k[f[x]]+2);
			sum[f[x]]+=t[x]/(k[x]+2);
			val[f[x]].insert(query(x));
			add(f[f[x]]),add(f[x]);
			if (f[x]!=f[f[f[x]]]) add_v(f[x]);
		} else if (op==2) {
			read(x);
			printf("%lld\n",query(x)+t[f[x]]/(k[f[x]]+2));
		} else {
			printf("%lld %lld\n",*all.begin(),*all.rbegin());
		}
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