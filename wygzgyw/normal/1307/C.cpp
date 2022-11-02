#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,cnt[30],t;
char s[maxn];
ll dp[30][30],ans;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) {
		t=s[i]-'a';
		for (int j=0;j<26;j++)
			dp[t][j]+=cnt[j];
		cnt[t]++;
	}
	for (int i=0;i<26;i++) {
		ans=max(ans,(ll)cnt[i]);
		for (int j=0;j<26;j++)
			ans=max(ans,dp[i][j]);
	}
	printf("%lld\n",ans);
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