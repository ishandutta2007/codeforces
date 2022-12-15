#include <bits/stdc++.h>
using namespace std;

string s; int i, p, b;

int main(){
	cin >> s;
	while(s.back()=='/'&&s.size()>1) 
		s.pop_back();
	for(i=0;i<s.size();i++){
		if(s[i] == '/' && p) continue;
		printf("%c",s[i]); p=0;
		if(s[i]=='/') p=1;
	}
	return 0;
}