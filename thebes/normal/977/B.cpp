#include <bits/stdc++.h>
using namespace std;

map<string,int> cnt;
int n, i, mx; string s, ans;

int main(){
	cin >> n >> s;
	for(i=0;i<n-1;i++)
		cnt[s.substr(i,2)]++;
	for(auto v : cnt)
		if(v.second>mx) mx=v.second,ans=v.first;
	cout << ans;
	return 0;
}