#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,p[19]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int v[40][4],tot;
ll q[40];
ll n,ans;
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
ll gen(ll n,ll k) {
  	ll t=powl(n,1./k)-0.5;
  	return t+(powl(t+1,k)-0.5<=n);
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int t=1;t<(1<<18);t++) {
		ll tmp=1;
		for (int i=1;i<=18;i++)
			if (t&(1<<(i-1))) {
				tmp=tmp/gcd(tmp,p[i])*p[i];
				if (tmp>63) break;
			}
		if (tmp<=63) {
			tot++;
			q[tot]=tmp;
			for (int i=1;i<=18;i++)
				if (t&(1<<(i-1)))
					v[tot][++v[tot][0]]=p[i];
		}
	}
	read(T);
	while (T--) {
		read(n);
		ans=0;
		ll tmp,t2;
		for (int t=1;t<=tot;t++) {
			if (v[t][0]%2==0) tmp=-1; else tmp=1;
			t2=gen(n,q[t]);
			ans+=tmp*t2;
		}
		printf("%lld\n",n+1-ans);
	}
	return 0;
}