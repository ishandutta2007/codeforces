
// Problem : A. Start Up
// Contest : Codeforces - Coder-Strike 2014 - Finals (online edition, Div. 1)
// URL : https://codeforces.com/contest/420/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	bool good =1 ;
	for(int i = 0; i<s.size(); i++){
		if(s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] =='G' || s[i] == 'J' || s[i] == 'K' || s[i] == 'L' || s[i] == 'N' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S' || s[i] == 'Z'){
			good = 0;
		}
	}
	for(int i = 0; i<s.size(); i++){
		if(s[i] != s[s.size()-i-1]){
			good = 0;
		}
	}
	cout << (good ? "YES\n" : "NO\n");
}