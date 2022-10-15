#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt[26]={};
	string s;
	cin >> s;
	for(char c : s)
		++cnt[c-'a'];
	int nLet=0;
	for(int i=0; i<26; ++i)
		nLet+=cnt[i]>0;
	if(nLet%2==0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";
}