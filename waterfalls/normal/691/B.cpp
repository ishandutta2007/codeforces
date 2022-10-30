#include <bits/stdc++.h>
using namespace std;

char s[1013];
char rev[213];

void make() {
	rev['A'] = 'A';
	rev['b'] = 'd';
	rev['d'] = 'b';
	rev['H'] = 'H';
	rev['I'] = 'I';
	rev['M'] = 'M';
	rev['O'] = 'O';
	rev['o'] = 'o';
	rev['p'] = 'q';
	rev['q'] = 'p';
	rev['T'] = 'T';
	rev['U'] = 'U';
	rev['V'] = 'V';
	rev['v'] = 'v';
	rev['W'] = 'W';
	rev['w'] = 'w';
	rev['X'] = 'X';
	rev['x'] = 'x';
	rev['Y'] = 'Y';
}

int main() {
	make();
	scanf(" %s",&s);
	int r = strlen(s)-1;
	for (int l=0;l<=r;l++,r--) {
		if (rev[s[l]]!=s[r]) printf("NIE\n"), exit(0);
	}
	printf("TAK\n");

	return 0;
}