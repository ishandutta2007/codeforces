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
const int maxn=(2e5)+10;
int n,m;
ll x[maxn],y[maxn];
vector<pair<int,int> > V[maxn];
int ans[maxn];
int S=500;
int fdL(int l,int k,int mod) {
	int res=l/mod*mod+k;
	if (res<l) res+=mod;
	return res;
}
int fdR(int r,int k,int mod) {
	int res=r/mod*mod+k;
	if (res>r) res-=mod;
	return res;
}
vector<int> buc[maxn];
int s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for (int i=1;i<=m;i++) {
		int op,k;
		read(op),read(k);
		if (op==1) V[k].push_back(MP(i,0));
		else V[k].back().second=i-1;
	}
	for (int i=1;i<=n;i++) if ((int)V[i].size()&&V[i].back().second==0) V[i].back().second=m;
	for (int i=1;i<=n;i++) if ((int)V[i].size()) {
		if (x[i]+y[i]>S) {
			for (auto [l,r] : V[i]) {
				ll now=l;
				while (1) {
					ll L=now+x[i],R=min((ll)r,now+x[i]+y[i]-1);
				//	printf("%lld %lld\n",L,R);
					if (L<=R) ans[L]++,ans[R+1]--;
					else break;
					now+=x[i]+y[i];
				}
			}
		} else buc[x[i]+y[i]].push_back(i);
	}
	for (int i=1;i<=m;i++) ans[i]+=ans[i-1];
	for (int z=1;z<=S;z++) if ((int)buc[z].size()) {
		for (int i=1;i<=m;i++) s[i]=0;
		for (int &i : buc[z]) {
			for (int v=x[i];v<x[i]+y[i];v++) {
				int k=v%(x[i]+y[i]);
				for (auto [l,r] : V[i]) {
					int L=fdL(l,(k+l)%z,x[i]+y[i]),R=fdR(r,(k+l)%z,x[i]+y[i]);
					if (L>R) continue;
				//	printf("z=%d %d %d %d %d %d\n",z,l,r,k,L,R);
					s[L]++;
					if (R+z<=m) s[R+z]--;
				}
			}
		}
		for (int i=z;i<=m;i++) s[i]+=s[i-z];
		for (int i=1;i<=m;i++) ans[i]+=s[i];
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
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