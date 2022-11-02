#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,T;
char s[maxn];
int mn[maxn];
int main() {
	read(T); while (T--) {
		read(n); scanf("%s",s+1);
		for (int i=1;i<=n;i++) mn[i]=n+1;
		long long ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j+=i) if (s[j]=='1') break; else mn[j]=min(mn[j],i);
		}
		for (int i=1;i<=n;i++) if (s[i]=='0') ans+=mn[i]; printf("%lld\n",ans);
	}
	return 0;
}