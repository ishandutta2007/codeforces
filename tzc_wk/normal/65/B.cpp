#include <bits/stdc++.h>
using namespace std;
string sol(string s,string prev){
	string ans="a";
	for(int i=0;i<4;i++){
		for(char c='0';c<='9';c++){
			if(c=='0'&&i==0)	continue;
			char tmp=s[i];
			s[i]=c;
			if(s<prev||s>"2011"){
				s[i]=tmp;
				continue;
			}
			ans=min(ans,s);
			s[i]=tmp;
		}
	}
	if(ans<prev||ans>"2011")	throw "No solution";
	return ans;
}
string s[1001];
vector<string> ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	cin>>s[i];
	string ts="0000";
	for(int i=0;i<n;i++){
		try{
			string a=sol(s[i],ts);
			ts=a;
//			cout<<a<<endl;
			ans.push_back(a);
		}
		catch(const char* s){
			printf("%s\n",s);
			return 0;
		}
	}
	for(int i=0;i<ans.size();i++)	cout<<ans[i]<<"\n";
}