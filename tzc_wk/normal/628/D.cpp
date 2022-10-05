#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
string minus1(string s){
	int r=s.size()-1;
	while(s[r]=='0'){
		s[r]='9';
		r--;
	}
	s[r]-=1;
	if(s[0]=='0')	s=s.substr(1,s.size()-1);
	return s;
}
int dp[2002][2002][2],a[2002],d,m,len=0;
int dfs(int pos,int rem,bool limit,bool appear){
	if(pos==-1)	return (rem==0&&appear);
	if(!limit&&dp[pos][rem][appear]!=-1)	return dp[pos][rem][appear];
	int up=(limit)?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		if((len-pos)%2==1){
			ans=(ans+dfs(pos-1,(rem*10+i)%m,(limit&&i==a[pos]),appear&&!(i==d)))%MOD;
		}
		else	ans=(ans+dfs(pos-1,(rem*10+i)%m,(limit&&i==a[pos]),appear&&(i==d)))%MOD;
	}
	if(!limit)	dp[pos][rem][appear]=ans;
	return ans;
}
int solve(string s){
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		a[s.size()-1-i]=s[i]-'0';
	}
	len=s.size();
	return dfs(s.size()-1,0,1,1);
}
bool ok(string s){
	int rem=0;
	bool b1=0,b2=0;
	for(int i=0;i<s.size();i++){
		rem=(rem*10+s[i]-'0')%m;
		if(i%2==1&&s[i]-'0'!=d)	b1=1;
		else if(i%2==0&&s[i]-'0'==d)	b2=1;
	}
	if(!rem&&!b1&&!b2)	return true;
	return false;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>m>>d;
	string s,t;
	cin>>s>>t;
	cout<<(solve(t)-solve(s)+ok(s)+MOD)%MOD<<endl;
}