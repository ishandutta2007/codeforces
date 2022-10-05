#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin>>s>>t;
	if(s.size()!=t.size()){cout<<"NO";return 0;}
	for(int i=0;i<s.size();i++){if(s[i]!=t[t.size()-1-i]){cout<<"NO";return 0;}}
	cout<<"YES";return 0;
}