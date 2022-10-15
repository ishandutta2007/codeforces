#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn=100007;
const int mod=1e9+7;
string s;
int ans=1;
int dp[maxn];

#undef int
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	dp[0]=dp[1]=1;
	for (int i=2;i<maxn;++i){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	int i=0,n=s.size();
	while (i<n){
		char c=s[i];
		int l=i;
		if (s[i]=='m'||s[i]=='w'){
			printf("0");
			return 0;
		}
		if (s[i]!='u'&&s[i]!='n'){
			i++;
			continue;
		}
		while(i<n&&s[i]==s[l]){
			i++;
		}
		ans=(ans*dp[i-l])%mod;
	}
	cout<<ans<<endl;
	return 0;
}