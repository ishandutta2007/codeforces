#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	string s;
	cin>>m>>n>>s;
	int pos;
	for(int i=0;i<m;i++){
	//cout<<i<<":"<<s.substr(0,i)<<" "<<s.substr(m-i,m-1)<<endl;
		if(s.substr(0,i)==s.substr(m-i,m-1))	pos=i;
	}
	//cout<<pos<<endl;
	cout<<s;
	for(int i=0;i<n-1;i++){
		cout<<s.substr(pos,m);
	}
	return 0;
}//