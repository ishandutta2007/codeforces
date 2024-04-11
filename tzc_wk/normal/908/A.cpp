#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')
			sum++;
	}
	cout<<sum<<endl;
	return 0;
}//