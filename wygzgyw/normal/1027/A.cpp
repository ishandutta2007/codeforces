#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;
bool ans;
char s[110];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		ans=1;
		for (int i=1;i<=n/2;i++)
			if (s[i]!=s[n-i+1]&&abs(s[i]-s[n-i+1])!=2) {
				ans=0; break;
			}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}