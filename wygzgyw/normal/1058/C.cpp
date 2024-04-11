#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int n,d[maxn],sum;
char s[maxn];
bool check(int i) {
	int tmp=0,flag=1,cnt=0;
	for (int j=1;j<=n;j++) {
		tmp+=d[j];
		if (tmp==i) tmp=0,cnt++;
		else if (tmp>i) return 0;
	}
	if (flag&&cnt*i==sum&&cnt>1) return 1;
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		d[i]=s[i]-'0';
	for (int i=1;i<=n;i++)
		sum+=d[i];
	for (int i=0;i<=sum;i++)
		if (check(i)) {
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}