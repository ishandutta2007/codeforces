#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,s,x; cin>>t>>s>>x;
	x-=t;
	if(x<0||x==1) goto no;
	x%=s;
	if(x>1) goto no;
	cout<<"YES\n";
	return 0;
	no:;
	cout<<"NO\n";
}