#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,ans;
int a[maxn],b[maxn];
char s[maxn],t[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=1;i<=n;i++) {
		a[i]=a[i-1];
		if (s[i]==t[a[i]+1]) a[i]++;
	}
	b[n+1]=m+1;
	for (int i=n;i>=1;i--) {
		b[i]=b[i+1];
		if (s[i]==t[b[i]-1]) b[i]--;
	}
	//for (int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
	int j=1;
	for (int i=1;i<=n;i++) {
		j=max(j,i);
		while (b[j+1]<=a[i]+1&&j<n) {
			j++;
		}
		//printf(" %d %d\n",i,j);
		if (b[j]==a[i]+1&&i<j) ans=max(ans,j-i-1);
	}
	for (int i=1;i<=n;i++)
		if (b[i]==1) ans=max(ans,i-1);
	for (int i=1;i<=n;i++)
		if (a[i]==m) ans=max(ans,n-i);
	printf("%d\n",ans);
	return 0;
}