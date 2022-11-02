#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int n,d[maxn],a[maxn],b[maxn];
char s[maxn];
int ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		d[i]=s[i]-'0';
		read(a[i]),read(b[i]);
	}
	for (int t=0,ss;t<=100000;t++) {
		ss=0;
		for (int i=1;i<=n;i++) ss+=d[i];
		ans=max(ans,ss);
		for (int i=1;i<=n;i++) {
			if (t>=b[i]&&(t-b[i])%a[i]==0) d[i]^=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}