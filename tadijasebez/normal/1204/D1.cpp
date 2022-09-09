#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	for(int i=s.size()-1,bal=0;~i;i--){
		if(s[i]=='0')bal++;
		else if(bal)bal--;
		else s[i]='0';
	}
	cout<<s<<"\n";
	return 0;
}