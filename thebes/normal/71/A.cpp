#include <bits/stdc++.h>
using namespace std;

string s; int n, i;

int main(){
	for(scanf("%d",&n);i<n;i++){
		cin >> s;
		if(s.size() > 10) printf("%c%d%c\n",s[0],s.size()-2,s[s.size()-1]);
		else printf("%s\n",s.c_str());
	}
	return 0;
}