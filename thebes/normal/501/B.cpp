#include <bits/stdc++.h>
using namespace std;

int N, i, k;
map<string,string> mp;
string s, t;

int main(){
	for(scanf("%d",&N);i<N;i++){
		cin >> s >> t;
		if(mp.count(s)){
			mp[t] = mp[s];
			mp.erase(s);
		}
		else mp[t] = s;
	}
	printf("%d\n",mp.size());
	for(auto v : mp){
		printf("%s %s\n",v.second.c_str(),v.first.c_str());
	}
	return 0;
}