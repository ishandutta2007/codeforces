#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,a,b;
char s[maxn];
int d[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		if (s[i]=='(') {
			if (a>b) b++,d[i]=1;
			else a++,d[i]=0;
		} else {
			if (a>b) a--,d[i]=0;
			else b--,d[i]=1;
		}
	}
	for (int i=1;i<=n;i++) printf("%d",d[i]);
	printf("\n");
	return 0;
}