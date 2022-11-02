#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n;
ll a[maxn],b[maxn],s[maxn],ans,H;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(H);
	for (int i=1;i<=n;i++) read(a[i]),read(b[i]);
	for (int i=1;i<n;i++)
		s[i]=s[i-1]+a[i+1]-b[i];
	ans=H+b[n]-a[n];
	for (int i=1;i<n;i++) {
		if (a[i+1]-b[i]>=H) {
			ans=max(ans,H+b[i]-a[i]);
			continue;
		}
		int l=i,r=n-1,res=0;
		while (l<=r) {
			int mid=(l+r)/2;
			if (s[mid]-s[i-1]<H) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,H-(s[res]-s[i-1])+b[res+1]-a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}