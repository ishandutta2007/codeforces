#include <bits/stdc++.h>
using namespace std;

int w;

int main() {
	scanf("%d",&w);
	printf("%s\n",(w%2==0 && w>2) ? "YES" : "NO");

	return 0;
}