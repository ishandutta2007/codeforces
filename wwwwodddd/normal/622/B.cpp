#include <iostream>
#include <cstdio>
using namespace std;
int n, m, x;
int main() {
	scanf("%d:%d", &n, &m);
	scanf("%d", &x);
	m += x;
	n += m / 60;
	m %= 60;
	n %= 24;
	printf("%02d:%02d\n", n, m);
}