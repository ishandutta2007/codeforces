#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,a[maxn],b[maxn],ans,tmp;
map<int,int> T;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(tmp);
	for (int i=1;i<=n;i++) read(a[i]);
	read(m); read(tmp);
	for (int i=1;i<=m;i++) read(b[i]);
	ans=2;
	for (int dx=1;dx<=(1e9);dx*=2) {
		T.clear();
		for (int i=1;i<=n;i++) {
			tmp=a[i]%(2*dx);
			T[tmp]++;
			ans=max(ans,T[tmp]);
		}
		for (int i=1;i<=m;i++) {
			tmp=(b[i]+dx)%(2*dx);
			T[tmp]++;
			ans=max(ans,T[tmp]);
		}
	}
	printf("%d\n",ans);
	return 0;
}