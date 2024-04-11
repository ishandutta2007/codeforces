#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(4e5)+10;
int n,tot,N,tr[maxn];
ll d[maxn];
ll sum[maxn],ans,t;
map<ll,int> id;
void add(int x) {
	for (;x<=N;x+=x&(-x)) tr[x]++;
}
ll query(int x) {
	ll res=0;
	for (;x>0;x-=x&(-x)) res+=tr[x];
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(t);
	int x;
	for (int i=1;i<=n;i++) {
		read(x);
		sum[i]=sum[i-1]+x;
	}
	for (int i=1;i<=n;i++)
		d[++tot]=sum[i],d[++tot]=t+sum[i];
	d[++tot]=t;
	sort(d+1,d+(tot+1));
	for (int i=1;i<=tot;i++)
		if (d[i]!=d[i-1])
			id[d[i]]=++N;
	for (int i=n;i>=1;i--) {
		add(id[sum[i]]);
		ans+=query(id[t+sum[i-1]]-1);
	}
	printf("%lld\n",ans);
	return 0;
}