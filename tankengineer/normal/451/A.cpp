#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	puts((min(n, m) & 1) ? "Akshat" : "Malvika");
	return 0;
}