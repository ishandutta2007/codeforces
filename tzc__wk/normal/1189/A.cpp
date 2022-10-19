#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	int n;cin>>n;
	cin>>s;
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')	cnt1++;
		else			cnt2++;
	}
	if(cnt1==cnt2){
		cout<<"2\n";
		cout<<s[0]<<" ";
		for(int i=1;i<s.size();i++)	cout<<s[i];
		cout<<endl;
	}
	else	cout<<"1\n"<<s<<endl;
	return 0;
}