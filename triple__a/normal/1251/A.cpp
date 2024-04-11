#include<bits/stdc++.h>
using namespace std;

string s;

bool ck[27];
int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>s;
		memset(ck,0,sizeof(ck));
		int n=s.size(),t=1;
		for (int i=0;i<n;++i){
			if (i<n-1&&s[i]==s[i+1]){
				t++;
			}
			else{
				if (t&1){
					ck[s[i]-'a']=1;
				}
				t=1;
			}
		} 
		for (int i=0;i<26;++i){
			if (ck[i]) printf("%c",i+'a');
		}
		cout<<endl;
	}
	return 0;
}