#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(1LL<<32);
int T,a,tot;
ll n,d[100010];
char s[10];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	d[0]=1;
	while (T--) {
		scanf("%s",s+1);
		if (s[1]=='a') {
			n+=d[tot];
			if (n>=INF) { printf("OVERFLOW!!!\n"); return 0; }
		} else if (s[1]=='e') {
			tot--;
		} else {
			read(a);
			tot++;
			d[tot]=d[tot-1]*a;
			d[tot]=min(d[tot],INF);
		}
	}
	printf("%lld\n",n);
	return 0;
}