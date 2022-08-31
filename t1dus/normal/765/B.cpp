#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char curr='a';
string s;
int n;
int main(){
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i] > curr){
			cout<<"NO"<<endl;
			return 0;
		} else if (s[i]==curr){
			curr++;
		}
	}
	cout<<"YES"<<endl;
}