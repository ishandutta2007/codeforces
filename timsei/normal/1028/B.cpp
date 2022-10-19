#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

int main(void) {
	for(int i = 1; i <= 2230; ++ i) {
		if(i & 1) putchar('4'); else putchar('5');
	}
	puts("");
	for(int i = 1; i <= 2229; ++ i) if(i & 1) putchar('5'); else putchar('4');
	putchar('5');
	puts(""); 
}