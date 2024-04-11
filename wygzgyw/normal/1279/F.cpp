#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(1e6)+10;
int n,k,l,ans,d[maxn];
char s[maxn];
pair<int,int> dp[maxn],tmp;
bool solve(int mid) {
	for (int i=1;i<=n;i++) {
		tmp=dp[i-1];
		tmp.first+=d[i];
		dp[i]=tmp;
		if (i>=l) {
			tmp=dp[i-l];
			tmp.first+=mid;
			tmp.second++;
			dp[i]=min(dp[i],tmp);
		}
	}
	return dp[n].second<=k;
}
void work() {
	int l=0,r=n,mid,res;
	while (l<=r) {
		mid=(l+r)/2;
		if (solve(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	solve(res);
	ans=min(ans,dp[n].first-res*k);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k); read(l);
	if (k>n/l) { printf("0\n"); return 0; }
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if ('a'<=s[i]&&s[i]<='z') d[i]=1,ans++;
	ans=min(ans,n-ans);
	work();
	for (int i=1;i<=n;i++) d[i]^=1;
	work();
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/