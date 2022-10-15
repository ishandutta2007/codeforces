#include<bits/stdc++.h>
using namespace std;

string s;

bool ck(string s,int n){
	for (int i=1;i<n;++i){
		if (s[i]=='1') return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	int n=s.size();
	if ((n&1)&&ck(s,n)){
		cout<<(n+1)/2;
	}
	else{
		cout<<n/2;
	}
	return 0;
}