#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int i=0;
	while(i<s.size()){
		if(s[i]=='-'&&s[i+1]=='.'){
            cout<<1;
            i+=2;
        }
        if(s[i]=='.'){
            cout<<0;
            i++;
        }
        if(s[i]=='-'&&s[i+1]=='-'){
            cout<<2;
            i+=2;
        }
	}
	return 0;
}