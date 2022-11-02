#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const int N=(1e6)+10;
int n,ans,tot,prime[N];
ll a[maxn];
bool vis[N];
map<ll,bool> M;
void solve(ll x) {
	if (M[x]) return;
	M[x]=1;
	ll sum=0;
	for (int i=1;i<=n;i++) {
		if (a[i]<x) sum+=x-a[i];
		else sum+=min(a[i]%x,x-a[i]%x);
		if (sum>=ans) return;
	}
	if (sum<ans) ans=sum;
}
void insert(ll x) {
	if (x<=0) return;
	for (int i=1;i<=tot;i++) {
		if (x/prime[i]<prime[i]) break;
		if (x==1) break;
		if (x%prime[i]!=0) continue;
		solve(prime[i]);
		while (x%prime[i]==0) x/=prime[i];
	}
	if (x>1) solve(x);
}
int main() {
	//freopen("1.txt","r",stdin);
	srand(time(0));
	int tmp;
	for (int i=2;i<N;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			tmp=i*prime[j];
			if (tmp>=N) break;
			vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		if (a[i]&1) ans++;
	}
	random_shuffle(a+1,a+n+1);
	double T1=clock(),T2;
	ll x;
	for (int i=1;i<=500;i++) {
		x=a[i];
		for (int i=-5;i<=5;i++) insert(x+i);
		T2=clock();
		if ((T2-T1)/CLOCKS_PER_SEC>2.4) break;
	}
	printf("%d\n",ans);
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