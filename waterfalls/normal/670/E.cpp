#include <bits/stdc++.h>
using namespace std;

int n,m,p;
char s[500013];
char op[500013];
int link[500013];
list<int> pos;

int main() {
	scanf("%d%d%d",&n,&m,&p);
	scanf(" %s %s",&s,&op);
	stack<int> has;
	for (int i=0;i<n;i++) {
		if (s[i]=='(') has.push(i);
		else {
			link[has.top()] = i;
			link[i] = has.top();
			has.pop();
		}
	}
	for (int i=0;i<n;i++) pos.push_back(i);
	auto it = pos.begin();
	for (int i=0;i<p-1;i++) ++it;
	for (int i=0;i<m;i++) {
		if (op[i]=='L') --it;
		if (op[i]=='R') ++it;
		if (op[i]=='D') {
			int a = min(*it,link[*it]);
			int b = max(*it,link[*it]);
			while (*it>a) --it;
			while (it!=pos.end() && *it<=b) it = pos.erase(it);
			if (it==pos.end()) --it;
		}
	}
	for (int i: pos) printf("%c",s[i]);
	printf("\n");

	return 0;
}