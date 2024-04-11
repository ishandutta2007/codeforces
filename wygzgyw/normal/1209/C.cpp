#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n;
char s[maxn];
int ans[maxn],d[maxn];
void solve() {
	int t1,t2,flag;
	for (int x=0;x<10;x++) {
		t1=0,t2=x; flag=1;
		for (int i=1;i<=n;i++) {
			if (d[i]>=t2) t2=d[i],ans[i]=2;
			else if (d[i]>=t1) t1=d[i],ans[i]=1;
			else { flag=0; break; }
		}
		if (t1>x) flag=0;
		if (flag) {
			for (int i=1;i<=n;i++) printf("%d",ans[i]);
			printf("\n");
			return;
		}
	}
	printf("-\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) d[i]=s[i]-'0';
		solve();
	}
	return 0;
}