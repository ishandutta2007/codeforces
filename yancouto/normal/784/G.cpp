#include <iostream>
using namespace std;

char s[112345];

int main() {
	int i;
	scanf("%s", s);
	int a = atoi(s);
	for(i = 0; s[i]; i++) {
		if(s[i] == '+') a += atoi(s + i + 1);
		else if(s[i] == '-') a -= atoi(s + i + 1);
	}
	while(a > 255) a -= 256;
	while(a < 0) a += 256;
	int w = 0;
	bool fst = true;
	while(a > 0 || fst) {
		fst = false;
		int b = a % 10;
		printf(">+++++[-<++++++++++>]<--");
		while(b) b--, putchar('+');
		a /= 10;
		putchar('>'); w++;
	}
	while(w > 0) {
		putchar('<');
		putchar('.');
		w--;
	}
	putchar('\n');
}