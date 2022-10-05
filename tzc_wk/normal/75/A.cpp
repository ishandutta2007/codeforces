#include <bits/stdc++.h>
using namespace std;
string tostr(int n){
	string ans="";
	while(n){
		char c=n%10+'0';
		ans=c+ans;
		n/=10;
	}
	return ans;
}
int tonum(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==' ')	continue;
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
string clear(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')	s[i]=' ';
	}
	return s;
}
int main(){
	string a,b;
	cin>>a>>b;
	string sum=tostr(tonum(a)+tonum(b));
	a=clear(a);b=clear(b);sum=clear(sum);
	if(tonum(a)+tonum(b)==tonum(sum)){
		cout<<"YES"<<endl;
	}
	else	cout<<"NO"<<endl;
	return 0;
}