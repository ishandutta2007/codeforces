#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int eq=0;
	for(int i=0; i<s.size() ;i++) eq+=(s[i]==s[0]);
	if(eq>=s.size()-1){
		cout << "Impossible\n";
		return 0;
	}
	for(int i=1; i<s.size() ;i++){
		string t=s.substr(s.size()-i,i)+s.substr(0,s.size()-i);
		bool ok=true;
		for(int j=0; j<s.size()/2 ;j++) if(t[j]!=t[s.size()-j-1]) ok=false;
		bool e=true;
		for(int j=0; j<s.size() ;j++) if(t[j]!=s[j]) e=false;
		if(e) ok=false;
		if(ok){
			cout << "1\n";
			return 0;
		}
	}
	cout << "2\n";
}