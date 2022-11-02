#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,dp[30][maxn];
char s[maxn],t[maxn];
int cnt[30],ans,len;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		x=s[i]-'a'+1;
		cnt[x]++;
		dp[x][cnt[x]]=i;
	}
	read(m);
	while (m--) {
		scanf("%s",t+1);
		len=strlen(t+1);
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for (int i=1;i<=len;i++) {
			x=t[i]-'a'+1;
			cnt[x]++;
			ans=max(ans,dp[x][cnt[x]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}