#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,m,a,b,lst;
ll x,s1[maxn],s2[maxn];
map<ll,int> T;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x);
		s1[i]=s1[i-1]+x;
	}
	read(m);
	for (int i=1;i<=m;i++) {
		read(x);
		s2[i]=s2[i-1]+x;
		T[s2[i]]=i;
	}
	if (s1[n]!=s2[m]) {
		printf("-1\n");
		return 0;
	}
	a=b=1;
	int ans=0;
	while (a<=n&&b<=m) {
		lst=a;
		while (a<n) {
			if (T[s1[a]-s1[lst-1]+s2[b-1]]) break;
			a++;
		}
		b=T[s1[a]-s1[lst-1]+s2[b-1]]+1;
		a++;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}