#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int n=(int)s.length();
	if(n%2==1){
		cout<<-1;
		return 0;
	}
	int x=0,y=0;
	for(int i=0;i<n;i++){
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		if(s[i]=='U')y--;
		if(s[i]=='D')y++;
	}
	cout<<(abs(x)+abs(y))/2;
	return 0;	
}