#include <bits/stdc++.h>
using namespace std;

string s;
int a[30], j;

int main(){
	cin >> s; s += ('z'+1);
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			memset(a, 0, sizeof(a));
			a[s[i-1]-'a']++;
			a[s[i+1]-'a']++;
			for(j=0;a[j];j++){}
			s[i] = 'a'+j;
		}
	}
	s.erase(s.end()-1);
	printf("%s\n",s.c_str());
	return 0;
}