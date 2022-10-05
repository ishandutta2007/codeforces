#include <bits/stdc++.h>
using namespace std;
string s,buf;
string ans;
bool first=false;
int main(){
	cin>>s;
	if(s.find('@')==s.npos)	return puts("No solution"),0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='@')	buf.push_back(s[i]);
		else{
			if(!first){
				first=true;
				if(buf.empty())
					return puts("No solution"),0;
				else
					ans+=buf+"@";
			}
			else{
				if(buf.size()<=1)
					return puts("No solution"),0;
				else
					ans.push_back(buf[0]),
					ans+=","+buf.substr(1,buf.size()-1)+"@";
			}
			buf.clear();
		}
	}
	if(buf.empty())	return puts("No solution"),0;
	ans+=buf;
	cout<<ans<<endl;
}