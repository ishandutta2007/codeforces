#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		int a,b;
		if(s[i]>='a')	a=s[i]-'a';
		else			a=s[i]-'A';
		if(t[i]>='a')	b=t[i]-'a';
		else			b=t[i]-'A';
		if(a>b)			return puts("1"),0;
		else if(a<b)	return puts("-1"),0;
	}
	puts("0");
}