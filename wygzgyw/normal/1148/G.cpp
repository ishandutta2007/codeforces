#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
const int N=10000000;
bool vis[N+10];
int tot,prime[N+10];
int n,a[maxn],deg[maxn],k;
vector<int> p[maxn];
int f[N+10];
void insert(int i,int pos,int now,int delta) {
	if (pos==(int)p[i].size()) {
		if (now!=1) f[now]+=delta; return;
	}
	insert(i,pos+1,now,delta);
	insert(i,pos+1,now*p[i][pos],delta);
}
void insert(int i) { insert(i,0,1,1); }
void del(int i) { insert(i,0,1,-1); }
int F,G,H;
void getGH() {
	for (int i=1;i<=n;i++) if (i!=F&&__gcd(a[i],a[F])==1) {
		if (!G) G=i; else if (!H) H=i;
	}
}
int query(int i,int pos,int now,int delta) {
	if (pos==(int)p[i].size()) return delta*f[now];
	return query(i,pos+1,now,delta)+query(i,pos+1,now*p[i][pos],-delta);
}
int query(int i) { return query(i,0,1,-1); }
int check(int m) {
	int m0=m;
	for (int i=1;i<=m;i++) {
		if (i!=F&&i!=G&&i!=H) insert(i); else m0--;
	}
	int cnt=0;
	for (int i=1;i<=m;i++) if (i!=F&&i!=G&&i!=H) {
		deg[i]=m0-query(i);
		if (deg[i]>0) cnt++;
	}
	for (int i=1;i<=m;i++) if (i!=F&&i!=G&&i!=H) del(i);
	return cnt;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n); read(k); n=2*k;
	for (int i=2;i<=N;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			if (i*prime[j]>N) break;
			vis[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	} int tmp;
	for (int i=1;i<=n;i++) {
		read(a[i]);
		tmp=a[i];
		for (int j=1;j<=tot&&prime[j]*prime[j]<=tmp;j++) if (tmp%prime[j]==0) {
			while (tmp%prime[j]==0) tmp/=prime[j];
			p[i].push_back(prime[j]);
		}
		if (tmp>1) p[i].push_back(tmp);
		insert(i);
	}
	
	for (int i=1;i<=n;i++) {
		deg[i]=query(i);
		if (!F&&deg[i]<=n-2) F=i,getGH();
	}
	if (!F) {
		for (int i=1;i<=n;i++) del(i);
		for (int i=1,cnt=0;i<=n&&cnt<k;i++) {
			if (query(i)==cnt) {
				cnt++;
				printf("%d ",i);
				insert(i);
			}
		}
		puts(""); return 0;
	}
	for (int i=1;i<=n;i++) del(i);
	if (check(n)<k-3) {
		for (int i=1,cnt=0;i<=n&&cnt<k;i++) {
			if (!deg[i]) { printf("%d ",i); cnt++; }
		} puts("");
	} else {
		int l=k-3,r=n,mid,m=-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)>=k-3) r=mid-1,m=mid;
			else l=mid+1;
		}
		int p=check(m);
		if (p>=k) {
			for (int i=1;i<=m&&p>k;i++) {
				if (i!=F&&i!=G&&i!=H&&deg[i]==1&&__gcd(a[i],a[m])==1) deg[i]=0,p--;
			}
		} else {
			for (int i=1;i<=m&&p>k-2;i++)
				if (i!=F&&i!=G&&i!=H&&deg[i]==1&&__gcd(a[i],a[m])==1) deg[i]=0,p--;
			printf("%d %d ",F,G);
			if (p==k-3) printf("%d ",H);
		}
		for (int i=1;i<=m;i++) if (i!=F&&i!=G&&i!=H&&deg[i]) printf("%d ",i);
		puts("");
	}
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