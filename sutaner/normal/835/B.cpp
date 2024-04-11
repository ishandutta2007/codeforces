#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 1000005
using namespace std;
char s[maxn];
int k;
int d;
int n;
int num[10];
void work(){
	for (int i = 0; i < n; i++) num[s[i] - '0']++, d += s[i] - '0';
	d = k - d;
	if (d <= 0) {printf("0");return;}
	int ans = 0;
	for (int i = 0; i < 9; i++){
		if (d - num[i] * (9 - i) <= 0){
			 ans += (d % (9 - i) == 0) ? d / (9 - i) : (d / (9 - i) + 1);
			 printf("%d", ans);
			 return;
		}
		d -= num[i] * (9 - i);
		ans += num[i];
	}
	printf("%d", ans);
}
int main(){
	/*freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);*/
	scanf("%d%*c%s", &k, s);
	n = strlen(s);
	work();
	return 0;
}