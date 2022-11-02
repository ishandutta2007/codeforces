#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=510;
int n,m,cnt,a1,a2,a3,a4;
char s[maxn][maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++)
			if (s[i][j]=='*') cnt++;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		if (s[i][j]!='*') continue;
		a1=a2=a3=a4=0;
		for (int k=i;k>=1;k--)
			if (s[k][j]=='*') a1++;
			else break;
		for (int k=i;k<=n;k++)
			if (s[k][j]=='*') a2++;
			else break;
		for (int k=j;k>=1;k--)
			if (s[i][k]=='*') a3++;
			else break;
		for (int k=j;k<=m;k++)
			if (s[i][k]=='*') a4++;
			else break;
		if (a1>1&&a2>1&&a3>1&&a4>1&&a1+a2+a3+a4-3==cnt) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}