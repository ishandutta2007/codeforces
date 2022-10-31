#include <string>
#include <iostream>
using namespace std;

int process(string s) {
	int bad0 = 0, bad1 = 0;
	for (int i=0;i<s.size();i+=2) bad0+=s[i]!='b';
	for (int i=1;i<s.size();i+=2) bad1+=s[i]!='r';
	return max(bad0,bad1);
}

int solve(string s) {
	int ans = process(s);
	for (char& c: s) c = 'b'+'r'-c;
	ans = min(ans,process(s));
	return ans;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << solve(s) << endl;

	return 0;
}