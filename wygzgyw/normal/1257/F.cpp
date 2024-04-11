#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(2e5);
int n,a[110],tot;
map<ll,int> head;
int nxt[maxn],to[maxn];
int d[110],b[110];
ll haxi() {
	ll tmp=0;
	for (int i=1;i<n;i++)
		tmp=(tmp*2011+d[i]+30)%mod;
	return tmp;
}
void add(ll x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void ck(int x) {
	int y,tmp=-1,cnt;
	for (int i=1;i<=n;i++) {
		y=x^a[i]; cnt=0;
		for (int j=0;j<30;j++)
			if (y&(1<<j)) cnt++;
		if (tmp==-1) tmp=cnt;
		else if (tmp!=cnt) return;
	}
	printf("%d\n",x);
	exit(0);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	int x;
	for (int t=0;t<(1<<15);t++) {
		for (int i=1;i<=n;i++) {
			x=a[i]^t;
			b[i]=0;
			for (int j=0;j<15;j++)
				if (x&(1<<j)) b[i]++;
		}
		for (int i=1;i<n;i++) d[i]=b[i+1]-b[i];
		add(haxi(),t);
	}
	ll tmp;
	for (int t=0;t<(1<<15);t++) {
		for (int i=1;i<=n;i++) {
			x=a[i]^(t<<15);
			b[i]=0;
			for (int j=15;j<30;j++)
				if (x&(1<<j)) b[i]++;
		}
		for (int i=1;i<n;i++) d[i]=b[i]-b[i+1];
		tmp=haxi();
		for (int i=head[tmp];i;i=nxt[i]) {
			ck((t<<15)+to[i]);
		}
	}
	printf("-1\n");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/