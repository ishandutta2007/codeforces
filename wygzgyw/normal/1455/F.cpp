#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,k,t;
string dp[510],s;
char ch;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k); cin>>s;
		dp[0]="";
		for (int i=1;i<=n;i++) dp[i]="{";
		for (int i=0;i<n;i++) {
			t=s[i]-'a';
			ch=min(min(t,(t+1)%k),(t+k-1)%k)+'a';
			dp[i+1]=min(dp[i+1],dp[i]+ch);
			if (i) dp[i+1]=min(dp[i+1],dp[i-1]+ch+s[i-1]),dp[i+1]=min(dp[i+1],dp[i].substr(0,i-1)+s[i]+dp[i].back());
			if (i>1) dp[i+1]=min(dp[i+1],dp[i-1].substr(0,i-2)+s[i]+dp[i-1].back()+s[i-1]);
		}
		cout<<dp[n]<<endl;
	}
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