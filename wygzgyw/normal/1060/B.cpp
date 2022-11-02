#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll n;
int flag,s;
int d[15],tot,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	while (n) d[++tot]=n%10,n/=10,s+=d[tot];
	for (int i=1;i<tot;i++) {
		if ((!flag&&d[i]<=8)||flag) flag=1,ans++;
		else flag=0;
	}
	printf("%d\n",s+9*ans);
	return 0;
}