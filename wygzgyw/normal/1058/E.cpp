#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+5;
typedef long long ll;
int n,a[maxn],mx;
ll x,ans,s,c1,c2;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int tmp;
	for (int i=1;i<=n;i++) {
		read(x);
		tmp=0;
		while (x) tmp+=x%2,x/=2;
		a[i]=tmp; s+=tmp;
		if (s%2==0) c1++; else c2++;
	}
	ans=c1*(c1+1)/2+c2*(c2-1)/2;
	for (int i=1;i<=n;i++) {
		mx=s=0;
		for (int j=i;j<=i+65&&j<=n;j++) {
			mx=max(mx,a[j]);
			s+=a[j];
			if (mx>s-mx&&s%2==0) ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}