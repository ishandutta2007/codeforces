#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	while (n--) {
		string s;
		scanf(" IAO'");
		cin >> s;
		int low = 1988;
		int ten = 10;
		for (int i=s.size()-1;i>=0;i--) {
			string t = s.substr(i);
			int cur = stoi(t);
			while (cur<=low) cur+=ten;
			low = cur;
			ten*=10;
		}
		printf("%d\n",low);
	}

	return 0;
}