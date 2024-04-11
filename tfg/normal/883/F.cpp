#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define X first
#define Y second
using namespace std;

string modify(string s){
	fr(i,0,s.size()){
		int k=i;
		while(k&&s[k]=='u'&&s[k-1]=='o'){
			swap(s[k],s[k-1]);
			k--;
		}
	}
	fr(i,0,s.size()-1){
		if(s[i]=='o'&&s[i+1]=='o'){
			s[i]='u';
			s=s.substr(0,i+1)+s.substr(i+2);
		}
	}
	for(int i=s.size()-1;i;i--){
		if(s[i]=='h'&&s[i-1]=='k'){
			s[i-1]='h';
			s=s.substr(0,i)+s.substr(i+1);
		}
	}
	return s;
	
}
int main() {
	string s;
	int n;
	set<string> sss;
	cin>>n;
	fr(i,0,n){
	cin>>s;
	sss.insert(modify(s));
	}
	cout<<sss.size()<<endl;
}