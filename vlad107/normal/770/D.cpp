#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	int mb = 0;
	int cb = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '[') ++cb; else --cb;
		mb = max(mb, cb);
	}
	vector<string> ans(3 + (mb - 1) * 2);
	cb = 0;
	int l = (int)ans.size();
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '[') {
		  	for (int j = 0; j < cb; j++) ans[j] += "  ";
			ans[cb] += "+-";
			for (int j = cb + 1; j < l - cb - 1; j++) ans[j] += "| ";
			ans[l - cb - 1] += "+-";
			for (int j = l - cb; j < l; j++) ans[j] += "  ";
			if (s[i + 1] == ']') {
			  	for (auto &t : ans) t += " ";
			}
			++cb;
		} else {
		  	--cb;
		  	for (int j = 0; j < cb; j++) ans[j] += "  ";
			ans[cb] += "-+";
			for (int j = cb + 1; j < l - cb - 1; j++) ans[j] += " |";
			ans[l - cb - 1] += "-+";
			for (int j = l - cb; j < l; j++) ans[j] += "  ";
		}
	}

	vector<string> ans2(ans.size());
	for (int j = 0; j < (int)ans[0].size(); j++) {
	  	bool add = false;
		bool spaces = true;
		for (int i = 0; i < (int)ans.size(); i++) {
		  	if (ans[i][j] != ' ') {
			  	spaces = false;
				break;
			}
		}
		if (spaces) add = true;
		if (ans2[0].empty()) {
			add = true;
		} else {
		  	spaces = true;
			for (int i = 0; i < (int)ans.size(); i++) {
				if (ans2[i].back() != ' ') {
					spaces = false;
					break;
				}
			}
			if (spaces) add = true;
			for (int i = 0; i < (int)ans.size(); i++) {
				if ((ans2[i].back() != ' ') && (ans[i][j] != ' ')) {
				  	add = true;
					break;
				}
			}
		}
		if (add) {
			for (int i = 0; i < (int)ans.size(); i++) ans2[i] += ans[i][j];
		} else {
			for (int i = 0; i < (int)ans.size(); i++) if (ans2[i].back() == ' ') ans2[i].back() = ans[i][j];
		}
	}
	for (auto s: ans2) cout << s << endl;
}