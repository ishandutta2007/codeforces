#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool f1=1,f2=1;
	string s1="",s2="",s3;
	int k=0;
	for(int i=0; i<=s.length(); i++){
		if(i==s.length()||s[i]==','||s[i]==';'){
			if(k==i)
				s2+=',';
			else{
				s3=s.substr(k,i-k)+',';
				if(!f1||f1&&s3[0]=='0'&&s3.length()>2)
					s2+=s3;
				else
					s1+=s3;
			}
			k=i+1;
			f1=true;
		}
		else
			if(s[i]>'9'||s[i]<'0')
				f1=0;
	}
	if(s1.length())
		s1="\""+s1.substr(0,s1.length()-1)+"\"";
	else
		s1="-";
	if(s2.length())
		s2="\""+s2.substr(0,s2.length()-1)+"\"";
	else
		s2="-";
	cout<<s1<<'\n'<<s2<<'\n';
	return 0;
}