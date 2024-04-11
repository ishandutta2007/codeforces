#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 101010;
const long long MAXK = 1010101010101010101ll;
const char s[100] = "What are you doing at the end of the world? Are you busy? Will you save us?";
const char t[3][100] = {"What are you doing while sending \"",
	"\"? Are you busy? Will you send \"",
	"\"?"};
int n;
long long len[MAXN], lt[3];
long long k;
char search(int n, long long k)
{
	if(n == 0)
		return s[k - 1];
	if(k <= lt[0])
		return t[0][k - 1];
	if(k <= lt[0] + len[n - 1])
		return search(n - 1, k - lt[0]);
	if(k <= lt[0] + len[n - 1] + lt[1])
		return t[1][k - lt[0] - len[n - 1] - 1];
	if(k <= lt[0] + len[n - 1] + lt[1] + len[n - 1])
		return search(n - 1, k - lt[0] - len[n - 1] - lt[1]);
	return t[2][k - lt[0] - len[n - 1] - lt[1] - len[n - 1] - 1];
}
void solve()
{
//	n = 1;
//	static int tmp = 0;
//	k = ++tmp;
	scanf("%d%I64d", &n, &k);
	if(k > len[n])
	{
		printf(".");
		return;
	}
	search(n, k);
	printf("%c", search(n, k));
}
int main()
{
	len[0] = strlen(s);
	int tmp = (lt[0] = strlen(t[0])) + (lt[1] = strlen(t[1])) + (lt[2] = strlen(t[2]));
	for(int i = 1; i <= MAXN - 10; i++)
		len[i] = min(MAXK, len[i - 1] * 2 + tmp);
	int T;
	for(scanf("%d", &T); T; T--)
		solve();
	return 0;
}