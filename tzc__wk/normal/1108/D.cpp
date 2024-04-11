#include <bits/stdc++.h>
using namespace std;
const char c[3]={'R','G','B'};
int n,ans=0;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		bool mark=false;
		char cc;
		while(s[i]==s[i+1]){
			cc=s[i];
			if(mark){
//				cout<<i<<endl;
				for(int j=0;j<3;j++){
					if(c[j]!=cc&&s[i+1]!=c[j])
						s[i]=c[j];
				}
				ans++;
			}
			mark=(mark+1)%2;
			i++;
		}
		if(mark){
//			cout<<i<<endl;
			for(int j=0;j<3;j++){
				if(c[j]!=cc&&s[i+1]!=c[j])
					s[i]=c[j];
			}
			ans++;
		}
	}
	cout<<ans<<endl<<s<<endl;
}