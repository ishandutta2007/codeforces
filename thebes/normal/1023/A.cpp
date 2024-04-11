#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, i, fl;

int main(){
	cin>>n>>m>>s>>t;
	if(s.find('*')!=string::npos&&n>m+1){printf("NO\n"); return 0;}
	else if(s.find('*')==string::npos&&n!=m){printf("NO\n"); return 0;}
	for(i=1;i<=s.size()&&i<=t.size();i++){
		if(s[s.size()-i]=='*') break;
		if(s[s.size()-i]!=t[t.size()-i]) fl=1;
	}
	for(i=0;i<s.size()&&i<t.size();i++){
		if(s[i]=='*') break;
		if(s[i]!=t[i]) fl=1;
	}
	printf("%s\n",(fl)?"NO":"YES");
	return 0;
}