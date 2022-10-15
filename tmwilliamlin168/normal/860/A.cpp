#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int bS=0;
	bool sameLet=true;
	s='a'+s;
	for(int i=1; i<s.size(); ++i) {
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
			bS=0;
			sameLet=true;
			cout << s[i];
			continue;
		}
		++bS;
		if(s[i-1]!='a'&&s[i-1]!='e'&&s[i-1]!='i'&&s[i-1]!='o'&&s[i-1]!='u'&&s[i-1]!=s[i])
			sameLet=false;
		if(!sameLet&&bS>=3) {
			cout << " ";
			bS=1;
			sameLet=true;
		}
		cout << s[i];
	}
}