#include <bits/stdc++.h>
using namespace std;


int n;
char buff[15];
string talk[200013];
set<string> has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		talk[i] = string(buff);
	}
	for (int i=n-1;i>=0;i--) {
		if (!has.count(talk[i])) printf("%s\n",talk[i].c_str());
		has.insert(talk[i]);
	}

	return 0;
}