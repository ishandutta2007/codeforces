#include <bits/stdc++.h>
using namespace std;

#define int long long

int sol(string s,string t){
	//cout<<"call "<<s<<" "<<t<<"\n";
	for(int i=0;i<(int)s.size();i++){
		if(s[i]==t[i])continue;
		//try to insert something here in s
		int ans=0;
		s.insert(s.begin()+i,' ');
		for(char c='a';c<='z';c++){
			s[i]=c;
			vector<bool> ok(t.size());
			for(int j=0;j<(int)s.size();j++){
				if(s[j]==t[j])ok[j]=true;
				else break;
			}
			for(int j=0;j<(int)s.size();j++){
				if(s[s.size()-1-j]==t[t.size()-1-j])ok[t.size()-1-j]=true;
				else break;
			}
			bool add=true;
			for(bool b:ok)add&=b;
			if(add)ans++;
		} 
		return ans;
	}
	return LLONG_MAX; //shouldn't happen
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;cin>>n;
	string s,t;cin>>s>>t;
	cout<<sol(s,t)+sol(t,s)<<"\n";
}