#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,r[maxn];
char s[maxn];
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1); r[n+1]=n+1;
	for (int x=n;x>=1;x--) {
		r[x]=r[x+1];
		for (int k=1;k*2+x<=r[x];k++)
			if (s[x]==s[x+k]&&s[x]==s[x+2*k]) {
				r[x]=x+2*k; break;
			}
		//printf("%d %d\n",x,r[x]);
		ans+=n-r[x]+1;
	}
	printf("%lld\n",ans);
	return 0;
}