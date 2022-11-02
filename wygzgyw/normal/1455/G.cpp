#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int n,s;

struct node {
	ll delta;
	map<int,ll> dp;
	multiset<ll> mn;
};
vector<node> st;
char op[5];
void del(multiset<ll> &a,ll b) { a.erase(a.find(b)); }
void add(node &A,int x,ll val) {
	if (A.dp.count(x)) del(A.mn,A.dp[x]);
	A.dp[x]=val-A.delta;
	A.mn.insert(A.dp[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(s);
	node A; A.delta=0; A.dp[0]=0; A.mn.insert(0); st.push_back(A);
	int y; ll v;
	for (int i=1;i<=n;i++) {
		scanf("%s",op+1);
		if (op[1]=='s') {
			read(y),read(v);
			ll mn=st.back().delta+*(st.back().mn.begin());
			st.back().delta+=v;
			if (y!=s) add(st.back(),y,mn);
		} else if (op[1]=='i') {
			read(y);
			ll val=INF;
			if (st.back().dp.count(y)) {
				val=st.back().dp[y]+st.back().delta;
				del(st.back().mn,st.back().dp[y]);
				st.back().dp.erase(y);
			}
			st.push_back({}); add(st.back(),y,val);
			st.back().delta=0;
		} else {
			int sz=(int)st.size();
			if (st[sz-1].dp.size()>st[sz-2].dp.size()) swap(st[sz-1],st[sz-2]);
			node &A=st[sz-2];
			for (auto it : st[sz-1].dp) {
				int x=it.first; v=it.second;
				if (!A.dp.count(x)||A.dp[x]+A.delta>v+st[sz-1].delta) {
					if (A.dp.count(x)) del(A.mn,A.dp[x]);
					A.dp[x]=v+st[sz-1].delta-A.delta;
					A.mn.insert(A.dp[x]);
				}
			}
			st.pop_back();
		}
	}
	A=st.back();
	printf("%lld\n",*A.mn.begin()+A.delta);
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