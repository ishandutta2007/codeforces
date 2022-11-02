#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int cnt[10];
char str[MAXN + 5];
int main() {
	int n;
	scanf("%d%s", &n, str);
	for(int i=0;i<n;i++)
		cnt[str[i]-'0']++;
	int ans = min(cnt[8], n/11);
	printf("%d\n", ans);
}