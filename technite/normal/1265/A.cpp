#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k;
	cin>>i;
	while(i--){
		int f=0;
		string s;
		cin>>s;
		for(k=0;k<s.size();k++){
			if (k==0){
				if(s[k]=='?'){
				if (s[k+1]!='a'){
					s[k]='a';
				}
					
				else if(s[k+1]!='b'){
					s[k]='b';
				}
				else{
					s[k]='c';
				}	

			}
			}
			else if(k==(s.size()-1)){
				if(s[k]=='?'){
				if (s[k-1]!='a'){
					s[k]='a';
				}
				
				else if(s[k-1]!='b'){
					s[k]='b';
				}
				else{
					s[k]='c';
			}
			}
			}	
			else if(s[k]=='?'){
				if (s[k-1]!='a' && s[k+1]!='a'){
					s[k]='a';
				}	
				else if(s[k-1]!='b' && s[k+1]!='b'){
					s[k]='b';
				}
				else{
					s[k]='c';
				}	
					
				
			}
			if(s[k]==s[k-1]){
				cout<<"-1"<<endl;
				f=1;
				break;
			}	
		}
		if(f==0){
			cout<<s<<endl;	
		}
		
	}
	
	return 0;
}