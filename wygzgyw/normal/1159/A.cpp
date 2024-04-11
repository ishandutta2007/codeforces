#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,mn,ans;
char s[110];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); mn=n+1;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		if (s[i]=='-') ans--;
		else ans++;
		mn=min(mn,ans);
	}
	if (mn<0) ans=-mn; else ans=0;
	for (int i=1;i<=n;i++) {
		if (s[i]=='-') ans--;
		else ans++;
	}
	printf("%d\n",ans);
	return 0;
}