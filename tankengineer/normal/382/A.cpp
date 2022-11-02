#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string s1, s2, ans;

int main() {
	cin >> s1 >> s2;
	int left = 0, right = 0;
	for (int i = 0; i < (int)s1.size(); ++i) {
		if (s1[i] == '|') {
			break;
		}
		++left;
		ans += s1[i];
	}
	right = s1.size() - 1 - left;
	if ((left + right + s2.size()) % 2) {
		printf("Impossible\n");
		return 0;
	}
	int size = (left + right + s2.size()) / 2;
	if (left > size || right > size) {
		printf("Impossible\n");
		return 0;
	}
	for (int i = 0; i < size - left; ++i) {
		ans += s2[i];
	}
	ans += '|';
	for (int i = left + 1; i < (int)s1.size(); ++i) {
		ans += s1[i];
	}
	for (int i = size - left; i < (int)s2.size(); ++i) {
		ans += s2[i];	
	}
	cout << ans << endl;	
	return 0;
}