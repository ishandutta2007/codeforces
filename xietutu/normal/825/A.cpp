#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[105];
int main() {
	scanf("%d%s", &n, s + 1); 
	int t = 1;
	for (int i = n; i >= 1; --i) {
		int j = i;
		while (j >= 1 && s[j] == '1') --j;	
		m += (i - j) * t;
		t = t * 10;	
		i = j;
	}
	printf("%d\n", m);
}