#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
char s[MAXN + 5];
int abs(int x) {
	return x >= 0 ? x : -x;
}
int main() {
	int n, a = 0, b = 0, s1 = 0, s2 = 0;
	scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n/2;i++)
		if( s[i] == '?' ) a++;
		else s1 += (s[i] - '0');
	for(int i=n/2+1;i<=n;i++)
		if( s[i] == '?' ) b++;
		else s2 += (s[i] - '0');
	if( s2 - s1 == (a - b) / 2 * 9 )
		puts("Bicarp");
	else puts("Monocarp");
}