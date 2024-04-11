// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
// mylittlepony
using namespace std;

int main() {
	string s,t;
	cin >> s >> t;
	if(s == t) {
		cout << "YES\n";
		return 0;}
	if(s.length() != t.length()) {
		cout << "NO\n";
		return 0;}
		
	bool b =true;
	for(int i =0; i < s.length(); i++) if(s[i] == '1') {
		b =false;
		break;}
	if(b) {
		cout << "NO\n";
		return 0;}
	for(int i =0; i < t.length(); i++) if(t[i] == '1') {
		b =true;
		break;}
	if(!b) {
		cout << "NO\n";
		return 0;}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing