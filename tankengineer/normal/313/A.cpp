#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[55];

int main() {
	scanf("%s", &s);
	int l = strlen(s);
	if (s[0] == '-') {
	  int t = 0;
	  for (int i = 1; i < l - 2; ++i) {
	    t = t * 10 + (s[i] - '0');
		}
		if (l != 2 && s[l - 2] > s[l - 1]) {
		  t = t * 10 + (s[l - 1] - '0');
		} else if (l != 2) {
		  t = t * 10 + (s[l - 2] - '0');
		}
		t = -t;
		//cout << s[l - 1] << ' ' << s[l - 2] << endl;
		printf("%d\n", t);
	} else {
	  printf("%s\n", s);
	}
	return 0;
}