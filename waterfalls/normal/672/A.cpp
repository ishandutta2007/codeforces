#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	string s;
	for (int i=1;i<=1000;i++) s+=to_string(i);
	scanf("%d",&n);
	printf("%c\n",s[n-1]);

	return 0;
}