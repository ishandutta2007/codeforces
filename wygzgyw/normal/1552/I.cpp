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
typedef __int128 ull;
typedef long long ll;
const int mod=998244353;
int jc[110],n,m,cnt;
bool vis[110];
ull S[110];
int ans;
int id[110],bit[1048576];
int Pop(ull x) {
	return bit[x&1048575]+bit[(x>>20)&1048575]+bit[(x>>40)&1048575]+bit[(x>>60)&1048575]+bit[(x>>80)&1048575]+bit[(x>>100)&1048575];
}
void print(ull x) {
	printf("( ");
	for (int i=1;i<=n;i++) if (x>>(i-1)&1) printf("%d ",i);
	printf(")");
}
struct Comp {
	ull P;
	int szP;
	vector<ull> S,Z,Z2;
	
	void build() {
		if ((int)S.size()==1) {
			Z=S; P=S[0];
			return;
		}
		ans=(ll)ans*2%mod;
		Z={S[0]-(S[0]&S[1]),S[0]&S[1],S[1]-(S[0]&S[1])};
		P=(S[0]|S[1]);
		for (int i=2;i<(int)S.size();i++) {
			Z2.clear();
			vector<int> I;
			for (int j=0;j<Z.size();j++) if ((Z[j]&S[i])&&(Z[j]-(Z[j]&S[i]))) I.push_back(j);
			ull Z0=S[i]-(S[i]&P);
			if ((int)I.size()>=3) { puts("0"); exit(0); }
			if ((int)I.size()==0) {
				int l=-1,r=-1;
				for (int j=0;j<Z.size();j++) if (Z[j]&S[i]) { if (l==-1) l=j; r=j; }
				for (int j=0;j<Z.size();j++) if (((Z[j]&S[i])>0)!=(l<=j&&j<=r)) { puts("0"); exit(0); }
				if (l==0) {
					if (Z0) Z2.push_back(Z0);
					for (ull E : Z) Z2.push_back(E);
				} else if (r==(int)Z.size()-1) {
					for (ull E : Z) Z2.push_back(E);
					if (Z0) Z2.push_back(Z0);
				} else if (Z0) { puts("0"); exit(0); }
				else Z2=Z;
			} else if ((int)I.size()==2) {
				for (int j=0;j<Z.size();j++) if (((Z[j]&S[i])!=0)!=(I[0]<=j&&j<=I[1])) { puts("0"); exit(0); }
				if (Z0) { puts("0"); exit(0); }
				for (int j=0;j<I[0];j++) Z2.push_back(Z[j]);
				Z2.push_back(Z[I[0]]-(Z[I[0]]&S[i]));
				Z2.push_back(Z[I[0]]&S[i]);
				for (int j=I[0]+1;j<I[1];j++) Z2.push_back(Z[j]);
				Z2.push_back(Z[I[1]]&S[i]);
				Z2.push_back(Z[I[1]]-(Z[I[1]]&S[i]));
				for (int j=I[1]+1;j<Z.size();j++) Z2.push_back(Z[j]);
			} else {
				int l=-1,r=-1;
				for (int j=0;j<Z.size();j++) if ((Z[j]&S[i])!=0) {
					if (l==-1) l=j; r=j;
				}
				for (int j=0;j<Z.size();j++) if (((Z[j]&S[i])!=0)!=(l<=j&&j<=r)) { puts("0"); exit(0); }
				if (l!=I[0]&&r!=I[0]) { puts("0"); exit(0); }
				if (!Z0) {
					for (int j=0;j<I[0];j++) Z2.push_back(Z[j]);
					if (l==I[0]) Z2.push_back(Z[I[0]]-(Z[I[0]]&S[i])),Z2.push_back(Z[I[0]]&S[i]);
					else Z2.push_back(Z[I[0]]&S[i]),Z2.push_back(Z[I[0]]-(Z[I[0]]&S[i]));
					for (int j=I[0]+1;j<Z.size();j++) Z2.push_back(Z[j]);
				} else {
					if (l==0&&r==I[0]) {
						Z2.push_back(Z0);
						for (int j=0;j<I[0];j++) Z2.push_back(Z[j]);
						Z2.push_back(Z[I[0]]&S[i]),Z2.push_back(Z[I[0]]-(Z[I[0]]&S[i]));
						for (int j=I[0]+1;j<Z.size();j++) Z2.push_back(Z[j]);
					} else if (l==I[0]&&r==(int)Z.size()-1) {
						for (int j=0;j<I[0];j++) Z2.push_back(Z[j]);
						Z2.push_back(Z[I[0]]-(Z[I[0]]&S[i])),Z2.push_back(Z[I[0]]&S[i]);
						for (int j=I[0]+1;j<Z.size();j++) Z2.push_back(Z[j]);
						Z2.push_back(Z0);
					} else { puts("0"); exit(0); }
				}
			}
			Z=Z2;
			P|=S[i];
		}
	}
} C[110];
vector<int> g[110];
void dfs(int u) {
	C[cnt].S.push_back(S[u]);
	vis[u]=1;
	for (int v : g[u]) if (!vis[v]) dfs(v);
}
bool cmp(int x,int y) {
	if (C[x].szP!=C[y].szP) return C[x].szP>C[y].szP;
	return (int)C[x].S.size()<(int)C[y].S.size();
}
bool anc(int x,int y) {
	if (C[x].P==C[y].P) return (int)C[x].S.size()==1;
	return (C[x].P&C[y].P)==C[y].P;
}
vector<int> son[110];
int main() {
	for (int i=1;i<(1<<20);i++) bit[i]=bit[i-(i&(-i))]+1;
	read(n),read(m); ans=1;
	int x,y; m++;
	for (int i=1;i<=m;i++) {
		if (i<m) {
			read(x);
			while (x--) read(y),y--,S[i]|=(ull)1<<y;
		} else S[i]=((ull)1<<n)-1;
	}
	sort(S+1,S+m+1);
	m=unique(S+1,S+m+1)-S-1;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<i;j++) {
			ull tmp=(S[i]&S[j]);
			if (tmp!=0&&tmp!=S[i]&&tmp!=S[j]) g[i].push_back(j),g[j].push_back(i);
		}
	}
	for (int i=1;i<=m;i++) if (!vis[i]) cnt++,dfs(i),C[cnt].build();
	for (int i=1;i<=cnt;i++) for (int j=0;j<n;j++) if (C[i].P>>j&1) C[i].szP++;
	for (int i=1;i<=cnt;i++) id[i]=i;
	jc[0]=1; for (int i=1;i<=100;i++) jc[i]=(ll)jc[i-1]*i%mod;
	sort(id+1,id+cnt+1,cmp);
	for (int i=2;i<=cnt;i++) {
		int now=id[1];
		for (int j=2;j<i;j++) if (anc(now,id[j])&&anc(id[j],id[i])) now=id[j];
		son[now].push_back(id[i]);
	}
	for (int i=1;i<=cnt;i++) {
		for (ull E : C[i].Z) {
			int now=Pop(E);
			for (int j : son[i]) {
				if ((C[j].P&E)==C[j].P) now-=C[j].szP-1;
			}
			ans=(ll)ans*jc[now]%mod;
		}
	}
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