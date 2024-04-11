#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,k;
ll x,s[300010],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<=n;i++)
		read(x),s[i]=s[i-1]+x;
	ans=s[n]*k;
	sort(s+1,s+n);
	for (int i=1;i<k;i++)
		ans-=s[i];
	printf("%lld\n",ans);
	return 0;
}