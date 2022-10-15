#include <bits/stdc++.h>
using namespace std;
 
string s;
int a;
vector<string> v[1000000];
 
void dfs(int d=0) {
	int b=s.find(',', a);
	v[d].push_back(s.substr(a, b-a));
	a=b+1;
	b=s.find(',', a);
	int nc=stoi(s.substr(a, b-a));
	a=b+1;
	while(nc--)
		dfs(d+1);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> s;
	s+=',';
	while(a<s.size())
		dfs();
	int d=999999;
	while(!v[d].size())
		--d;
	cout << d+1 << "\n";
	for(int i=0; i<=d; ++i) {
		for(string s : v[i])
			cout << s << " ";
		cout << "\n";
	}
}