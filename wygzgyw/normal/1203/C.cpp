#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,cnt;
ll x,ans;
ll gcd(ll a,ll b) {
	if (!a||!b) return a+b;
	return gcd(b,a%b);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		read(x),ans=gcd(ans,x);
	for (ll i=1;i*i<=ans;i++)
		if (ans%i==0) {
			cnt++;
			if (ans/i!=i) cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}