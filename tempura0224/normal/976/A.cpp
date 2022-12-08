#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;


int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(s=="0")cout<<"0"<<endl;
	else {
		cout<<"1";
		rep(i,n)if(s[i]=='0')cout<<"0";
		cout<<endl;
	}
}