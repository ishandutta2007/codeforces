#include <bits/stdc++.h>
using namespace std;

int n, i;
string s;

int main(){
	cin >> n >> s;
	while(s[i]=='1'&&i<s.size()) i++;
	printf("%d\n",min((int)s.size(),i+1));
	return 0;
}