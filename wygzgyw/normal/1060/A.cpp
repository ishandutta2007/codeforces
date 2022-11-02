#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int n,cnt,ans;
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='8') cnt++;
	for (int i=1;i<=cnt;i++)
		if (n-i>=i*10) ans=i;
	printf("%d\n",ans);
	return 0;
}