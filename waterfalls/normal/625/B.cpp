#include <bits/stdc++.h>
using namespace std;

string s,t;
char buff[100013];

int main() {
	scanf(" %s",&buff);
	s = string(buff);
	scanf(" %s",&buff);
	t = string(buff);
	int ans = 0;
	for (int i=t.size();i<=s.size();i++) {
		if (s.substr(i-t.size(),t.size())==t) {
			s[i-1] = '#';
			ans+=1;
		}
	}
	printf("%d\n",ans);

	return 0;
}