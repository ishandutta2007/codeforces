#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
typedef long long ll;
ll n,s[maxn],tmp;
int tot;
void work(int a) {
	tmp=n/a;
	s[++tot]=tmp+(tmp*(tmp-1)/2)*a;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i*i<=n;i++) {
		if (n%i!=0) continue;
		work(i);
		if (n/i!=i) work(n/i);
	}
	sort(s+1,s+tot+1);
	for (int i=1;i<=tot;i++)
		printf("%lld ",s[i]); printf("\n");
	return 0;
}