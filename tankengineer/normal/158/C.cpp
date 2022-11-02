#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> stack;

vector<string> prase(char *s) {
	string ept;
	vector<string> ret;
	if (*s == '/') {
		++s;
	}
	for (int i = 0; s[i]; ++i) {
		string tmp;
		int j = i;
		while (s[j] != '/' && s[j] != '\0') {
			tmp += s[j];
			++j;
		}
		i = s[j] == '\0' ? j - 1 : j;
		ret.push_back(tmp);
	}
	return ret;
}
void process(char *s) {
	if (s[0] == '/') {
		stack.clear();
	}
	vector<string> tmp = prase(s);
	for (int i = 0; i < (int)tmp.size(); ++i) {
		if (tmp[i][0] == '.') {
			stack.pop_back();
		} else {
			stack.push_back(tmp[i]);
		}
	}
}
void print() {
	printf("/");
	for (int i = 0; i < (int)stack.size(); ++i) {
		printf("%s/", stack[i].c_str());
	}
	printf("\n");
}

int main() {
	int n;
	char commend[205], path[205];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", commend);
		if (commend[0] == 'p') {
			print();
		} else {
			scanf("%s", path);
			process(path);
		}
	}
	return 0;
}