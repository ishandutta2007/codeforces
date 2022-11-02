#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=1000;
int T,prime[maxn+10],tot,cnt,ans;
bool vis[maxn+10];
ll tmp;
ll query(ll x) {
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%lld",&x);
	cnt++;
	return x;
}
int solve(ll x) {
	ll y=x;
	while (y<=INF/x) y*=x;
	y=query(y);
	int res=0;
	while (y%x==0) y/=x,res++;
	return res;
}
int main() {
	for (int i=2;i<=maxn;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			tmp=i*prime[j];
			if (tmp>maxn) break;
			vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	read(T);
	while (T--) {
		cnt=0; ans=1;
		for (int i=1,j=1;i<=tot;i=j) {
			tmp=1;
			while (tmp<=INF/prime[j]) {
				tmp*=prime[j]; j++;
			}
			if (cnt==22) break;
			tmp=query(tmp);
			for (int k=i;k<j;k++) {
				if (cnt==22) break;
				if (tmp%prime[k]==0) {
					ans*=solve(prime[k])+1;
				}
			}
		}
		if (ans<=4) printf("! 8\n");
		else printf("! %d\n",ans*2);
	}
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