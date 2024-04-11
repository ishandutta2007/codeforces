#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string s;
	cin>>n>>s;
	int a=0,b=0;
	for(char c:s) if(c=='A') ++a; else ++b;
	if(a<b) cout<<"Danik\n";
	if(a>b) cout<<"Anton\n";
	if(a==b) cout<<"Friendship\n";
}