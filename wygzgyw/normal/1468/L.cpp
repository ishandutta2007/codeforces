#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
const ll INF=1e18;
int n,k;
bool vis[maxn];
ll imp[maxn];
int tot,c[maxn],totk;
vector<int> num;
vector<ll> D[1010];
vector<int> G[maxn];
bool flag,ok[1010],mk[maxn],im[maxn];
vector<ll> ans;
ll X[1010];
map<ll,int> dy,S;
bool cmp(int x,int y) {
	return (int)G[x].size()>(int)G[y].size();
}
int insert(ll x) {
	if (!dy[x]) {
		dy[x]=++tot;
		imp[tot]=x;
		return tot;
	}
	return dy[x];
}
ll checkp2(ll x) {
	ll p=sqrt(x*1.0);
	while (p*p<x) p++;
	while ((p-1)*(p-1)>=x) p--;
	if (p*p==x) {
		for (ll i=2;i*i<=p;i++) if (p%i==0) return 0;
		return p;
	}
	return 0;
}
int TOT,prime[maxn];
bool bad[1010];
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(k); ll x,y; int id;
	if (k==1) { puts("0"); return 0; }
	for (int i=2;i<maxn;i++) {
		if (!vis[i]) {
			prime[++TOT]=i;
			x=(ll)i*i;
			while (1) {
				if (x>INF/i) break;
				x=x*i;
				S[x]=i;
			}
		}
		for (int j=1;j<=TOT;j++) {
			if (prime[j]*i>=maxn) break;
			vis[prime[j]*i]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=n;i++) {
		read(x); X[i]=x;
		y=checkp2(x);
		if (y) insert(y);
		else if (S[x]) insert(S[x]);
	}
	for (int i=1;i<=n;i++) {
		x=X[i];
		for (int j=1;j<=tot;j++) if (x%imp[j]==0) {
			while (x%imp[j]==0) x/=imp[j];
			D[i].push_back(j);
		}
		if (x==1&&(int)D[i].size()==1) G[D[i][0]].push_back(i);
		if (x!=1) bad[i]=1;
	}
	for (int i=1;i<=tot;i++) {
		c[i]=(int)G[i].size();
		if (c[i]>1) {
		//	printf("%lld %d\n",imp[i],c[i]);
			im[i]=1,totk+=c[i];
			if (c[i]>2) flag=1;
			num.push_back(i);
		}
	}
	int mn=-1;
	for (int i=1;i<=n;i++) if (!bad[i]&&(int)D[i].size()!=1) {
		ok[i]=1;
		for (int j=0;j<D[i].size();j++)
			if (!im[D[i][j]]) { ok[i]=0; break; }
		if (ok[i]) {
			if (mn==-1||(int)D[i].size()<(int)D[mn].size()) mn=i;
		}
	}
	if (k<=totk) {
		if (!flag) {
			if (k&1^1) {
				for (int i=1;i<=tot;i++) if (im[i]) {
					printf("%lld %lld ",X[G[i][0]],X[G[i][1]]);
					k-=2;
					if (!k) { puts(""); return 0; }
				}
			} else {
				if (mn==-1||(int)D[mn].size()>k/2) { puts("0"); return 0; }
				printf("%lld ",X[mn]); k--;
				for (int i=0;i<D[mn].size();i++) {
					id=D[mn][i];
					printf("%lld %lld ",X[G[id][0]],X[G[id][1]]); k-=2;
					mk[id]=1;
				}
				for (int i=1;i<=tot;i++) if (im[i]&&!mk[i]) {
					if (!k) { puts(""); return 0; }
					printf("%lld %lld ",X[G[i][0]],X[G[i][1]]);
					k-=2;
				}
				puts("");
				return 0;
			}
		}
		sort(num.begin(),num.end(),cmp);
		int pos=0,L=0,cc=0;
		for (int i : num) {
			cc++;
			if (k-(int)G[i].size()>=0) {
				k-=(int)G[i].size(),pos=cc;
				for (int x : G[i]) ans.push_back(X[x]);
			}
			else break;
		}
		if (k) {
			if (k==1) L=1,k++;
			for (int x : G[num[pos]]) {
				if (!k) break;
				k--;
				ans.push_back(X[x]);
			}
		}
		for (int i=L;i<ans.size();i++) printf("%lld ",ans[i]);
		puts(""); return 0;
	}
	for (int i : num) for (int x : G[i]) ans.push_back(X[x]),k--;
	for (int i=1;i<=n;i++) if (ok[i]) {
		if (!k) break;
		k--;
		ans.push_back(X[i]);
	}
	if (k) { puts("0"); return 0; }
	for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]); puts("");
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