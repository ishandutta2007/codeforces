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
const int mod=998244353;
const int mod2=(1e9)+7;
ll n,cnt; int ans,sum[10];
vector<int> vec[10];
void update(int &x,int y) { x+=y; if (x>=mod2) x-=mod2; }
void dfs1(int dep,int val) {
	if (val>n) return;
	cnt++;
	vec[dep].push_back((cnt-val+mod)%mod);
	if (dep==6) return;
	for (int i=0;i<10;i++) dfs1(dep+1,val*10+i);
}
void dfs2(int dep,ll val) {
	if (val>n) return;
	if (dep>=1) {
		if ((ll)val*1000000>n/10&&(ll)val*1000000+999999<=n) {
			ll tmp=val;
			for (int i=0;i<=6;i++) {
				int cur=(cnt%mod-tmp%mod+mod)%mod;
				update(ans,(ll)cur*(int)vec[i].size()%mod2);
				int pos=vec[i].end()-lower_bound(vec[i].begin(),vec[i].end(),mod-cur);
				update(ans,(sum[i]-(ll)pos*mod%mod2+mod2)%mod2);
				tmp*=10;
			}
			for (int i=0;i<=6;i++) cnt+=(int)vec[i].size();
			return;
		}
		cnt++; update(ans,(cnt%mod-val%mod+mod)%mod);
	}
	for (int i=(dep==0?1:0);i<10;i++) dfs2(dep+1,(ll)val*10+i);
}
int main() {
	read(n);
	dfs1(0,0);
	for (int i=0;i<=6;i++) {
		sort(vec[i].begin(),vec[i].end());
		for (int &x : vec[i]) update(sum[i],x);
	}
	cnt=0;
	dfs2(0,0);
	printf("%d\n",ans);
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