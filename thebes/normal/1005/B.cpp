#include <bits/stdc++.h>
using namespace std;

string s, t;
int i;

int main(){
	cin >> s >> t;
	for(i=1;i<=min(s.size(),t.size());i++){
		if(s[s.size()-i]!=t[t.size()-i]) break;
	}
	printf("%d\n",s.size()+t.size()-2*(i-1));
	getchar(); getchar();
}