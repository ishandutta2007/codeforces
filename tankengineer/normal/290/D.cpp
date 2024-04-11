#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char a[55], s[55];

int main() {
	memset(a, 0, sizeof(a));
	scanf("%s %d", &s, &n);
	for (int i = 0; i < strlen(s); ++i) {
	  if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	  if (s[i] < n + 97) {
	    a[i] = s[i] - 'a' + 'A';
		} else {
			a[i] = s[i];
	  }
	}
	printf("%s\n", a);
	return 0;
}