#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> s;

int main() {
	scanf("%d",&n);
	if (n>26) return printf("-1\n"), 0;
	for (int i=0;i<n;i++) {
		char c;
		scanf(" %c",&c);
		s.push_back(c);
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	printf("%d\n",n-s.size());

	return 0;
}