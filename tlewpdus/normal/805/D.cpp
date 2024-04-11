#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

char str[1000100];
long long res = 0, MOD = 1000000007, cnt = 0;

int main() {
	int n, i;
	scanf("%s",str);
	n = strlen(str);
	for (i=n-1;i>=0;i--) {
		if (str[i]=='b') cnt++;
		else {
			res += cnt;
			cnt += cnt;
		}
		res %= MOD;
		cnt %= MOD;
	}
	printf("%I64d\n",res);
	return 0;
}