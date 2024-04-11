#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int h1, m1, h2, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	m1 -= m2;
	if (m1 < 0) {
		--h1;
		m1 += 60;
	}
	h1 -= h2;
	while (h1 < 0) {
		h1 += 24;
	}
	printf("%02d:%02d\n", h1, m1);
	return 0;
}