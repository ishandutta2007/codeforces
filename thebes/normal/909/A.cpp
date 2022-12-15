#include <bits/stdc++.h>
using namespace std;

string s, t, r, ans="zzzzzzzzzzzzzzzzzzzzzzzzzz";
int i, j;

int main(){
	cin >> s >> t;
	for(i=1;i<=s.size();i++){
		for(j=1;j<=t.size();j++){
			r = s.substr(0,i);
			r += t.substr(0,j);
			ans = min(r, ans);
		}
	}
	cout << ans;
	return 0;
}