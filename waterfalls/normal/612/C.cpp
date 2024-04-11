#include <bits/stdc++.h>
using namespace std;

char buff[1000013];
string s;
stack<int> has;
int val[1013];

int main() {
	val['<'] = 1; val['>'] = -1;
	val['{'] = 2; val['}'] = -2;
	val['['] = 3; val[']'] = -3;
	val['('] = 4; val[')'] = -4;
	scanf(" %s",&buff);
	s = string(buff);
	int ans = 0;
	for (int i=0;i<s.size();i++) {
		if (val[s[i]]<0) {
			if (has.size()==0) return printf("Impossible\n"), 0;
			if (has.top()!=-val[s[i]]) ans+=1;
			has.pop();
		} else has.push(val[s[i]]);
	}
	if (has.size()!=0) return printf("Impossible\n"), 0;
	printf("%d\n",ans);

	return 0;
}