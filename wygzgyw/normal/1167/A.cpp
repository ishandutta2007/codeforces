#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int T,n;
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); int pos=n;
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
			if (s[i]=='8') { pos=i; break; }
		if (n-pos+1>=11) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}