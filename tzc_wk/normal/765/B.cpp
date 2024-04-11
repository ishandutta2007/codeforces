#include <bits/stdc++.h>
using namespace std;
bool u[27];
vector<int> p;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!u[s[i]-'a'])	p.push_back(s[i]-'a');
			u[s[i]-'a']=1;
	}
	for(int i=1;i<26;i++){
		if(u[i]&&!u[i-1]){
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<p.size();i++){
		if(p[i]-p[i-1]!=1){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}