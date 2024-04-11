#include <bits/stdc++.h>
using namespace std;

char buff[1000013];
string s;

int main() {
	scanf(" %s",&buff);
	s = string(buff);
	int on = 0;
	while (s[on]=='0') on+=1;
	s = s.substr(on);
	int ind = find(s.begin(),s.end(),'.')-s.begin();
	int p;
	if (ind==0) {
		on = 1;
		while (s[on]=='0') on+=1;
		p = -on;
	} else p = ind-1;
	if (ind<s.size()) s.erase(s.begin()+ind);
	on = 0;
	while (s[on]=='0') on+=1;
	int a = s[on]-'0';
	string t = s.substr(on+1);
	while (t.size()>0 && t.back()=='0') t.pop_back();
	if (t.size()==0 || *max_element(t.begin(),t.end())=='0') printf("%d",a);
	else printf("%d.%s",a,t.c_str());
	if (p) printf("E%d",p);
	printf("\n");

	return 0;
}