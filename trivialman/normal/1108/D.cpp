#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 2010;

int n,ans=0;
string s;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>s;s=s+' ';
	rep(i,1,n-1)if(s[i]==s[i-1]){
		++ans;
		if(s[i-1]!='R'&&s[i+1]!='R')s[i]='R';
		else if(s[i-1]!='G'&&s[i+1]!='G')s[i]='G';
		else s[i]='B';
	}
	cout<<ans<<endl<<s.substr(0,n)<<endl;
	return 0;
}