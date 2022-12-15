#include <bits/stdc++.h>
using namespace std;

int n, m, i; unordered_map<string,string> id;
string s, t;

int main(){
	for(scanf("%d%d",&n,&m),i=0;i<n;i++){
		cin >> s >> t;
		id[t] = s;
	}
	for(i=0;i<m;i++){
		cin >> s >> t; t.pop_back();
		cout << s << " " << t << "; #";
		printf("%s\n",id[t].c_str());
	}
	return 0;
}