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
// mylittlepony
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i =0; i < s.length(); i++) if(s[i] == '0') {
		s.erase(s.begin()+i);
		cout << s << endl;
		return 0;}
	s.erase(s.begin());
	cout << s << endl;
	return 0;}

// look at my code
// my code is amazing