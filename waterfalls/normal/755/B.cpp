#include <bits/stdc++.h>
using namespace std;

int n,m,both;
set<string> one;
char buff[513];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		one.insert(string(buff));
	}
	int both = 0;
	for (int i=0;i<m;i++) {
		scanf(" %s",&buff);
		if (one.count(string(buff))) {
			both+=1;
		}
	}
	n-=both;
	m-=both;
	while (true) {
		if (both) both-=1;
		else if (n) n-=1;
		else return printf("NO\n"), 0;
		if (both) both-=1;
		else if (m) m-=1;
		else return printf("YES\n"), 0;
	}

	return 0;
}