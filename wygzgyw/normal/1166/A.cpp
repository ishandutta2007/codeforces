#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,cnt[30],ans;
char s[30];
int f(int x) {
	return x*(x-1)/2;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		cnt[s[1]-'a'+1]++;
	}
	for (int i=1;i<=26;i++) {
		ans+=f(cnt[i]/2)+f(cnt[i]-cnt[i]/2);
	} printf("%d\n",ans);
	return 0;
}