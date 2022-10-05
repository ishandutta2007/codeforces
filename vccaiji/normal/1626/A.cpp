#include<bits/stdc++.h>
using namespace std;
int a[26];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		string s;
		cin>>s;
		for(int i=0;i<26;i++) a[i]=0;
		for(int i=0;i<s.length();i++) a[s[i]-'a']++;
		for(int i=0;i<26;i++){
			for(int j=1;j<=a[i];j++){
				char c=i+'a';
				cout<<c;
			}
		}
		cout<<endl;
	}
	return 0;
}