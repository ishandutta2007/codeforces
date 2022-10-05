#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin>>t;
	int x;
	for(int i=0;i<t.size();i++){
		if(t[i]!='a')
			s+=t[i];
		else
			x=i;
	}
	cout<<(s.size()%2==0&&t.size()-x>s.size()/2&&s.substr(0,s.size()/2)==s.substr(s.size()/2,s.size())?t.substr(0,t.size()-s.size()/2):":(");
}