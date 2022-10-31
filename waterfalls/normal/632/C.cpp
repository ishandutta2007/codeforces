#include <bits/stdc++.h>
using namespace std;

int n;
char buff[53];
vector<string> has;

bool comp(string& a, string& b) { return a+b<b+a; }

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		has.push_back(string(buff));
	}
	sort(has.begin(),has.end(),comp);
	for (string& s: has) printf("%s",s.c_str());
	printf("\n");

	return 0;
}