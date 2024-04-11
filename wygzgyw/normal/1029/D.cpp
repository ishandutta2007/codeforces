#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9');
}
typedef long long ll;
const int maxn=(2e5)+5;
int n,v[maxn];
ll k,a[maxn],ans;
map<int,int> g[11];
int s(ll x) {
	int res=0;
	if (x==0) return 1;
	while (x) x/=10,res++;
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (register int i=1;i<=n;++i) {
		read(a[i]);
		v[i]=s(a[i]);
		g[v[i]][a[i]%k]++;
	}
	for (register int i=1;i<=n;++i) {
		ll t=1;
		for (register int j=1;j<=10;++j) {
			t*=10; t%=k;
			ans+=(ll)g[j][(k-a[i]*t%k)%k];
			if (j==v[i]&&a[i]*(t+1)%k==0) ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}