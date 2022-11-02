// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(1e5)+10;
int T,n;
char s[maxn];
int from[maxn];
bool dp[maxn];
bool chk(int x) { return x>=10&&x<=26; }
int main() {
	read(T); while (T--) {
		read(n);
		scanf("%s",s+1);
		dp[0]=1;
		for (int i=1;i<=n;i++) {
			dp[i]=0;
			if (dp[i-1]&&s[i]!='0') from[i]=1,dp[i]=1;
			else if (i>=3&&dp[i-3]&&s[i]=='0'&&chk((s[i-2]-'0')*10+s[i-1]-'0')) from[i]=2,dp[i]=1;
		}
		int x=n; vector<int> ans;
		while (x) {
			if (from[x]==1) ans.push_back(s[x]-'0'),x--;
			else ans.push_back((s[x-2]-'0')*10+s[x-1]-'0'),x-=3;
		}
		reverse(ans.begin(),ans.end());
		for (int &v : ans) printf("%c",'a'+v-1); puts("");
	}
	return 0;
}