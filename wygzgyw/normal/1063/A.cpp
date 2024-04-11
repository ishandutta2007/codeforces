#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n;
char s[maxn];
int main() {
	read(n); scanf("%s",s+1);
	sort(s+1,s+n+1);
	printf("%s\n",s+1);
	return 0;
}