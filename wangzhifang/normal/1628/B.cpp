#include <bits/stdc++.h>
using namespace std;
void test(){
	int n;
	set<string>st1,st2;
	for(cin>>n; n; --n){
		string x;
		cin>>x;
		st1.insert(x);
		st2.insert(x.substr(0,x.size()-1));
		reverse(x.begin(),x.end());
		if(st1.count(x)||st2.count(x)){
			for(; --n; cin>>x);
			puts("YES");
			return;
		}
		if(st1.count(x.substr(0,x.size()-1))){
			for(; --n; cin>>x);
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	for(cin>>t; t; test(),--t);
	return 0;
}