#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll n,k,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	ans=k/n;
	if (k%n!=0) ans++;
	printf("%lld\n",ans);
	return 0;
}