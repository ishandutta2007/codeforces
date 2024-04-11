#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int t;
string s;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>t;
	while(t--){
		cin>>s;
		bool flag=false;
		rep(i,1,s.size()-1)if(s[0]!=s[i])flag=true;
		sort(s.begin(),s.end());
		if(!flag)cout<<-1<<endl;
		else cout<<s<<endl;
	}
	return 0;
}