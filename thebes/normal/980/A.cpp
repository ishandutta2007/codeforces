#include <bits/stdc++.h>
using namespace std;

int cnt, fu, i;
string s;

int main(){
	cin >> s;
	for(char c : s){
		if(c=='-') cnt++;
		else fu++;
	}
	if(!fu) printf("YES\n");
	else printf("%s\n",(cnt%fu)?"NO":"YES");
	return 0;
}