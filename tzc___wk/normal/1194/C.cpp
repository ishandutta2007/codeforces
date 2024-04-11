#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
string s,t,p;
int cnt1[30],cnt2[30];
int dp[105][105];
int LIS(string s,string t){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<s.size();i++)
		for(int j=1;j<t.size();j++){
			if(s[i]==t[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	return dp[s.size()-1][t.size()-1];
}
int main(){
	DR1(T);
	while(T--){
		cin>>s>>t>>p;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		s=" "+s;
		t=" "+t;
		p=" "+p;
		int len=LIS(s,t);
		if(len!=s.size()-1){
			puts("NO");
			continue;
		}
		for(int i=1;i<t.size();i++){
			cnt1[t[i]-'a']++;
		}
		for(int i=1;i<s.size();i++){
			cnt1[s[i]-'a']--;
		}
		for(int i=1;i<p.size();i++){
			cnt2[p[i]-'a']++;
		}
		bool flag=1;
		for(int i=0;i<26;i++){
			if(cnt2[i]<cnt1[i])
				flag=0;
		}
		cout<<((flag)?"YES":"NO")<<endl;
	}
	return 0;
}