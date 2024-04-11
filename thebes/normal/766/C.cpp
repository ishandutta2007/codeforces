#include <bits/stdc++.h>
using namespace std;

const int MN = 1e3+3,mod=1e9+7;
int dp[MN], mn[MN], N, i, j, a[30], flag[30], mx;
string s; char p;

void solve(int n){
	p='1'; mn[n]=1<<30;
	memset(flag,0,sizeof(flag));
	for(int i=n;i<=N;i++){
		flag[s[i]-'a']=1; bool f=0;
		for(int j=0;j<26;j++)
			if(flag[j]&&i-n+1>a[j]) f=1;
		if(f) return;
		dp[n]=(dp[n]+dp[i+1])%mod;
		mn[n]=min(mn[n],1+mn[i+1]);
		mx = max(mx, i-n+1);
	}
}

int main(){
	cin >> N >> s; dp[N+1]=1; s.insert(s.begin(),' ');
	for(i=0;i<26;i++) cin>>a[i];
	for(i=N;i>=1;i--) solve(i);
	printf("%d\n%d\n%d\n",dp[1],mx,mn[1]);
	return 0;
}