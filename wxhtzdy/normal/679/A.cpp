#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

bool ask(int x)
{
	printf("%d\n", x);
	fflush(stdout);
	char ret[4];
	scanf("%s", ret);
	return ret[0] == 'y';
}

bool prime(int x) 
{
	for(int i = 2; i * i <= x; i ++) if(x % i == 0) return false;
	return true;
}

int main()
{
	int cnt = 0;
	for(int i = 2; i * i <= 50; i ++) if(prime(i) && ask(i * i)) cnt += 513141;
	for(int i = 2; i <= 50; i ++) if(prime(i) && ask(i)) cnt ++;
	puts(cnt <= 1 ? "prime" : "composite");
	fflush(stdout);
	return 0;
}