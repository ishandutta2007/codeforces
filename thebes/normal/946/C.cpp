#include <bits/stdc++.h>
using namespace std;

string s, t; int i;

int main(){
	cin >> s;
	for(char c : s){
		if(c<=i+'a'&&i!=26){
			t.push_back(i+'a');
			i++;
		}
		else t.push_back(c);
	}
	if(i==26) printf("%s\n",t.c_str());
	else printf("-1\n");
	return 0;
}