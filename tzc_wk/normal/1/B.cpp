#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
int n;
string tran1(int n)	{
	string ans="";
	while(n) {
		if(n%26==0) {
			ans='Z'+ans;
			n=n/26-1;
		}
		else {
			char c=n%26+'A'-1;
			ans=c+ans;
			n=n/26;
		} 
	}
	return ans;
}
int tran2(string s)	{
	int ans=0;
	rep(i,s.size())	{
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int tran3(string s)	{
	int ans=0;
	rep(i,s.size())	{
		ans=ans*26+s[i]-'A'+1;
	}
	return ans;	
}
bool type(string s) {
	if(s[0]=='R'&&s[1]<='9'&&s[1]>='0'&&s.find_last_of('C')!=-1)	return true;
	return false;
}
string s;
int main()
{
	/*cout<<tran2("1234")<<endl<<tran1(55)<<endl;*/
	cin>>n;
	rep(e,n){
		cin>>s;
		if(type(s)){
			int pos=s.find_last_of('C');
			//cout<<pos<<endl;
			string s1=s.substr(1,pos-1),s2=s.substr(pos+1,s.size()-1);
			cout<<tran1(tran2(s2))<<s1<<endl;
		}
		else {
			int pos;
			rep(i,s.size()){
				if(s[i+1]<='9'&&s[i+1]>='0'&&s[i]<='Z'&&s[i]>='A'){
					pos=i;
					break;
				}
			}
			string s1=s.substr(0,pos+1),s2=s.substr(pos+1,s.size()-1);
			cout<<"R"<<s2<<"C"<<tran3(s1)<<endl;
		}
	}
	return 0; 
}