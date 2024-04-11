#include<iostream>
using namespace std;
#include<string>
int main(){
	int t;
	cin>>t;
	string s;
	cin>>s;
	if(t==12){
		if(s.at(0)>='2'){
			if(s.at(1)=='0')
				s.at(0)='1';
			else
				s.at(0)='0';
		}
		else if(s.at(0)=='1'){
			if(s.at(1)>='3')
				s.at(1)='0';
		}
		else{
			if(s.at(0)=='0' && s.at(1)=='0')
				s.at(1)='1';

		}
	}
	else{
		if(s.at(0)>='3'){
			if(s.at(1)=='0')
				s.at(0)='1';
			else
				s.at(0)='0';
		}
		
		else if(s.at(0)=='2'){
			if(s.at(1)>='4')
				s.at(0)='1';
		}
	}
	if(s.at(3)>='6'){
			if(s.at(4)=='0')
				s.at(3)='1';
			else
				s.at(3)='0';
		}
		
		cout<<s;
}