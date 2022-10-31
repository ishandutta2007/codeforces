#include <bits/stdc++.h>
using namespace std;

string s;
char buff[200013];

int main() {
	scanf(" %s",&buff);
	s = string(buff);
	for (int i=1;i<s.size();i++) {
		if (s[i]==s[i-1]) {
			while (s[i]==s[i-1] || s[i]==s[i+1]) {
				s[i]+=1;
				if (s[i]>'z') s[i] = 'a';
			}
		}
	}
	printf("%s\n",s.c_str());

	return 0;
}