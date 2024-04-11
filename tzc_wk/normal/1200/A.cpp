#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool p[11];
int main(){
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='L'){
			for(int j=0;j<10;j++){
				if(!p[j]){
					p[j]=1;
					break;
				}
			}
		}
		else if(s[i]=='R'){
			for(int j=9;j>=0;j--){
				if(!p[j]){
					p[j]=1;
					break;
				}
			}
		}
		else{
			p[s[i]-'0']=0;
		}
	}
	for(int i=0;i<10;i++)	cout<<p[i];
	return 0;
}