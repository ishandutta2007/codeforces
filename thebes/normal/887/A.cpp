#include <bits/stdc++.h>
using namespace std;

string s;
int a, b, i;

int main(){
	getline(cin, s);
	for(i=0;i<(signed)s.size();i++){
		if(s[i] == '1') a = 1;
		else if(a) b++;
	}
	if(a && b >= 6) printf("yes\n");
	else printf("no\n");
	return 0;
}