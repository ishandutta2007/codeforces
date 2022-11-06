#include<stdio.h>
#include<string>
#include<iostream>
#include<set>
using namespace std;
set<string> S;
int main(){
	int n;
	string a, b;
	cin>>a>>b>>n;
	S.insert(a); S.insert(b);
	cout<<a<<' '<<b<<endl;
	for(int i=1; i<=n; i++){
		cin>>a>>b;
		S.erase(a);
		S.insert(b);
		for(auto x:S) cout<<x<<' ';
		cout<<endl;
	}
	return 0;
}