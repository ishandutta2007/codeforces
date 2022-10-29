#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,s,x;
int main() {
	scanf("%d%d%d", &t, &s, &x);
	if (x < t) printf("NO\n");
	else if (x == t) printf("YES\n");
	else {
		int mod = (x - t) % s;
		if (x >= t + s && (mod == 0 || mod == 1)) printf("YES\n");
		else printf("NO\n");
	}
}