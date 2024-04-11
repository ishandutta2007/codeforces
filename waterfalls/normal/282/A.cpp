#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int x = 0;
	for (int i=0;i<n;i++) {
		string s;
		cin >> s;
		if (s[1]=='+') x+=1;
		else x-=1;
	}
	cout << x;

	return 0;
}